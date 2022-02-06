#include "../include/camera.h"

camera_t *newCamera(vec3_t look_from, vec3_t look_at, vec3_t vup, double vfov,
                    double aspect_ratio, double aperture, double focus_dist) {
  camera_t *cam = malloc(sizeof(camera_t));
  double theta = degreesToRadians(vfov);
  double h = tan(theta / 2.0);
  double viewport_height = 2.0 * h;
  double viewport_width = aspect_ratio * viewport_height;

  vec3_t w = normalizeVec3(subVec3(look_from, look_at));
  vec3_t u = normalizeVec3(crossVec3(vup, w));
  vec3_t v = crossVec3(w, u);

  cam->w = w;
  cam->u = u;
  cam->v = v;

  cam->origin = look_from;
  cam->horizontal = mulVec3(u, viewport_width * focus_dist);
  cam->vertical = mulVec3(v, viewport_height * focus_dist);

  vec3_t llc = subVec3(look_from, mulVec3(w, focus_dist));
  llc = subVec3(llc, divVec3(cam->horizontal, 2.0));
  cam->lower_left_corner = subVec3(llc, divVec3(cam->vertical, 2.0));

  cam->lens_radius = aperture / 2.0;
  return cam;
}

ray_t getRay(camera_t *cam, double x, double y) {
  ray_t r;
  vec3_t rd = mulVec3(randInDiscVec3(), cam->lens_radius);
  vec3_t offset = addVec3(mulVec3(cam->u, rd.x), mulVec3(cam->v, rd.y));
  r.origin = addVec3(cam->origin, offset);
  r.direction = subVec3(cam->lower_left_corner, r.origin);
  r.direction = addVec3(r.direction, mulVec3(cam->horizontal, x));
  r.direction = addVec3(r.direction, mulVec3(cam->vertical, y));
  return r;
}
