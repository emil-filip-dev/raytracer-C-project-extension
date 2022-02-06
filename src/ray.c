#include "../include/ray.h"

vec3_t rayPos(const ray_t *r, double t) {
  return addVec3(r->origin, mulVec3(r->direction, t));
}
