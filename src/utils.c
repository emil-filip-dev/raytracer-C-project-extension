#include "../include/utils.h"

#define DBL_EPSILON 0.000001

bool doubleEquals(double a, double b) { return fabs(a - b) < DBL_EPSILON; }

double degreesToRadians(double degrees) { return degrees * PI / 180.0; }

double randDouble() { return ((double)rand()) / (RAND_MAX); }

double randDoubleRange(double min, double max) {
  return min + (max - min) * randDouble();
}

double clamp(double x, double min, double max) {
  double result = x < min ? min : x;
  return result > max ? max : result;
}
