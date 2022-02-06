#include "../include/hittable.h"

void freeHittable(hittable_t *h) {
  free(h->object_data);
  free(h);
}

void setFaceNormal(hit_record_t *rec, const ray_t *r,
                   const vec3_t outward_normal) {
  rec->front_face = dotVec3(r->direction, outward_normal) < 0;
  rec->normal = rec->front_face ? outward_normal : reverseVec3(outward_normal);
}

bool hitList(hittable_list_t *hl, const ray_t *r, double t_min, double t_max,
             hit_record_t *rec) {
  hit_record_t temp_rec;
  bool hit_anything = false;
  double closest_so_far = t_max;

  list_elem_t *le_ptr;
  for (hittable_t *h = (hittable_t *)listInterateReentrant(
           (list_t *)hl->object_data, &le_ptr);
       h != NULL; h = (hittable_t *)listInterateReentrant(NULL, &le_ptr)) {
    if (h->hit_func(h, r, t_min, closest_so_far, &temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      *rec = temp_rec;
    }
  }

  return hit_anything;
}

hittable_list_t *newHittableList() {
  hittable_list_t *hl = malloc(sizeof(hittable_list_t));
  if (hl == NULL) return NULL;
  list_t *l = newList();
  if (l == NULL) return NULL;
  hl->object_data = l;
  hl->hit_func = &hitList;
  hl->mat = NULL;
  return hl;
}

void hittableListAdd(hittable_list_t *hl, hittable_t *h) {
  listAdd((list_t *)hl->object_data, h);
}

void freeHittableList(hittable_list_t *hl) {
  freeList((list_t *)hl->object_data, (val_free_func)&freeHittable);
  free(hl);
}

bool sphereHit(hittable_t *s, const ray_t *r, double t_min, double t_max,
               hit_record_t *rec) {
  sphere_data *sd = (sphere_data *)s->object_data;
  vec3_t oc = subVec3(r->origin, s->position);
  double a = lengthSquaredVec3(r->direction);
  double half_b = dotVec3(oc, r->direction);
  double c = lengthSquaredVec3(oc) - sd->radius * sd->radius;

  double discriminant = half_b * half_b - a * c;
  if (discriminant < 0) return false;
  double sqrtd = sqrt(discriminant);

  double root = (-half_b - sqrtd) / a;
  if (root < t_min || root > t_max) {
    root = (-half_b + sqrtd) / a;
    if (root < t_min || root > t_max) {
      return false;
    }
  }

  rec->t = root;
  rec->point = rayPos(r, root);
  setFaceNormal(
      rec, r,
      normalizeVec3(divVec3(subVec3(rec->point, s->position), sd->radius)));
  rec->mat = s->mat;

  return true;
}

sphere *newSphere(vec3_t center, double radius, material_t *mat) {
  sphere *s = malloc(sizeof(sphere));
  if (s == NULL) return NULL;
  s->hit_func = &sphereHit;
  s->position = center;
  sphere_data *sd = (sphere_data *)malloc(sizeof(sphere_data));
  if (sd == NULL) return NULL;
  sd->radius = radius;
  s->object_data = sd;
  s->mat = mat;
  return s;
}
