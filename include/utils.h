#ifndef __UTILS_H__
#define __UTILS_H__

#define PI 3.1415926535897932385

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Converts from degrees to radians.
 */
double degreesToRadians(double degrees);

/*
 * Returns a random double between 0 and 1.
 */
double randDouble();

/*
 * Returns a random double between min and max.
 */
double randDoubleRange(double min, double max);

/*
 * Restricts the value x between min and max.
 *
 * If x is below min, returns min.
 * If x is above max, returns max.
 * Otherwise, returns x.
 */
double clamp(double x, double min, double max);

/*
 * Compares the value of two doubles, with accuracy DBL_EPSILON
 */
bool doubleEquals(double a, double b);

#endif  // __UTILS_H__
