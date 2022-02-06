#include "../include/vec3.h"

#define DELTA 0.0000001

vec3_t vec3(const double a, const double b, const double c) {
  return (vec3_t){a, b, c};
}

vec3_t addVec3(const vec3_t a, const vec3_t b) {
  vec3_t r;
  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z;
  return r;
}

vec3_t subVec3(const vec3_t a, const vec3_t b) {
  vec3_t r;
  r.x = a.x - b.x;
  r.y = a.y - b.y;
  r.z = a.z - b.z;
  return r;
}

vec3_t mulVec3(const vec3_t a, const double t) {
  vec3_t r;
  r.x = a.x * t;
  r.y = a.y * t;
  r.z = a.z * t;
  return r;
}

vec3_t divVec3(const vec3_t a, const double t) { return mulVec3(a, 1.0 / t); }

double dotVec3(const vec3_t a, const vec3_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3_t crossVec3(const vec3_t a, const vec3_t b) {
  vec3_t r;
  r.x = a.y * b.z - a.z * b.y;
  r.y = a.z * b.x - a.x * b.z;
  r.z = a.x * b.y - a.y * b.x;
  return r;
}

double lengthVec3(const vec3_t a) { return sqrt(lengthSquaredVec3(a)); }

double lengthSquaredVec3(const vec3_t a) { return dotVec3(a, a); }

vec3_t normalizeVec3(const vec3_t a) { return divVec3(a, lengthVec3(a)); }

vec3_t reverseVec3(const vec3_t v) { return mulVec3(v, -1); }

vec3_t randVec3() {
  vec3_t r;
  r.x = randDouble();
  r.y = randDouble();
  r.z = randDouble();
  return r;
}

vec3_t randRangeVec3(double min, double max) {
  vec3_t r;
  r.x = randDoubleRange(min, max);
  r.y = randDoubleRange(min, max);
  r.z = randDoubleRange(min, max);
  return r;
}

vec3_t randInSphereVec3() {
  return mulVec3(normalizeVec3(randRangeVec3(-1000.0, 1000.0)), randDouble());
}

vec3_t randUnitVec3() { return normalizeVec3(randInSphereVec3()); }

vec3_t randInDiscVec3() {
  vec3_t r;
  double theta = randDoubleRange(0.0, 2.0) * PI;
  r.x = cos(theta);
  r.y = sin(theta);
  r.z = 0.0;
  return mulVec3(r, randDouble());
}

vec3_t applyFuncVec3(const vec3_t a, double (*func)(double)) {
  vec3_t r;
  r.x = func(a.x);
  r.y = func(a.y);
  r.z = func(a.z);
  return r;
}

bool closeToZeroVec3(const vec3_t v) {
  double d = DELTA;
  return (v.x < d) && (v.y < d) && (v.z < d);
}

vec3_t reflectVec3(const vec3_t v, const vec3_t n) {
  return subVec3(v, mulVec3(n, 2 * dotVec3(v, n)));
}

vec3_t refractVec3(const vec3_t v, const vec3_t n, double etaRatio) {
  double cos_theta = fmin(dotVec3(mulVec3(v, -1), n), 1.0);
  vec3_t perp = mulVec3(addVec3(v, mulVec3(n, cos_theta)), etaRatio);
  vec3_t parallel = mulVec3(n, -sqrt(fabs(1.0 - lengthSquaredVec3(perp))));
  return addVec3(perp, parallel);
}

bool equalsVec3(const vec3_t v1, const vec3_t v2) {
  return doubleEquals(v1.x, v2.x) && doubleEquals(v1.y, v2.y) &&
         doubleEquals(v1.z, v2.z);
}
