#include "../include/utils.h"
#include <assert.h>

void testDegreesToRadians() {
  assert(doubleEquals(degreesToRadians(0), 0));
  assert(doubleEquals(degreesToRadians(90), PI / 2));
  assert(doubleEquals(degreesToRadians(180), PI));
  assert(doubleEquals(degreesToRadians(360), 2 * PI));
}

void testClamp() {
  assert(doubleEquals(clamp(0.5, 0, 1), 0.5));
  assert(doubleEquals(clamp(-0.5, 0, 1), 0));
  assert(doubleEquals(clamp(1.5, 0, 1), 1));
}

int main(void) {
  testDegreesToRadians();
  testClamp();
  return 0;
}
