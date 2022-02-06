#ifndef __VEC3_H_
#define __VEC3_H_

#include <stdbool.h>
#include <math.h>

#include "utils.h"

/*
 * A vector in 3-dimensional Eucledian space.
 */
typedef struct Vec3 {
  double x;
  double y;
  double z;
} vec3_t;

/*
 * Returns a new vector struct whose x, y, z components are equale to a, b, c
 * respectively.
 */
vec3_t vec3(const double a, const double b, const double c);

/*
 * Basic vector algebra functions.
 */
vec3_t addVec3(const vec3_t a, const vec3_t b);
vec3_t subVec3(const vec3_t a, const vec3_t b);
vec3_t mulVec3(const vec3_t a, const double t);
vec3_t divVec3(const vec3_t a, const double t);
double dotVec3(const vec3_t a, const vec3_t b);
vec3_t crossVec3(const vec3_t a, const vec3_t b);
double lengthVec3(const vec3_t a);
double lengthSquaredVec3(const vec3_t a);
vec3_t reverseVec3(const vec3_t v);
vec3_t normalizeVec3(const vec3_t a);

/*
 * Returns a vector whose components each take a random value between 0 and 1.
 */
vec3_t randVec3();

/*
 * Returns a vector whose components each take a random value between min and
 * max.
 */
vec3_t randRangeVec3(double min, double max);

/*
 * Returns a random vector in the unit sphere, i.e. a vector whose rotation
 * along the three directional axes is random and whose length is less than 1.
 */
vec3_t randInSphereVec3();

/*
 * Returns a random vector ON the unit sphere, i.e. a vector whose rotation
 * along the three directional axes is random and whose length is equal to 1.
 */
vec3_t randUnitVec3();

/*
 * Returns a random vector in the unit circle across the XY plane.
 * That is, the vector has a random rotation, a random length less than 1 and a
 * z component equal to 0.
 */
vec3_t randInDiscVec3();

/*
 * Applies the given function to all three components of the vector, and updates
 * each component to each respective function result.
 */
vec3_t applyFuncVec3(const vec3_t a, double (*func)(double));

/*
 * Returns true if the given vector has length close to 0.
 */
bool closeToZeroVec3(const vec3_t v);

/*
 * Reflects a given vector across a given normal.
 */
vec3_t reflectVec3(const vec3_t v, const vec3_t n);

/*
 * Refracts a given vector across a given normal and eta ratio.
 */
vec3_t refractVec3(const vec3_t v, const vec3_t n, double etaRatio);

/*
 * Compares two vectors pointwise, with accuracy DBL_EPSILON
 */
bool equalsVec3(const vec3_t v1, const vec3_t v2);

#endif  // __VEC3_H_
