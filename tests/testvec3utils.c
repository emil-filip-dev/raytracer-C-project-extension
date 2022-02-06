#include "../include/vec3.h"
#include "../include/utils.h"
#include <assert.h>
#include <math.h>

void test_add() {
  vec3_t v1 = (vec3_t){1, 2, 3};
  vec3_t v2 = (vec3_t){0, 0, 0};

  vec3_t vRes = addVec3(v1, v2);
  assert(equalsVec3(v1, vRes));

  v2 = (vec3_t){-3, -2, -1};
  vRes = addVec3(v1, v2);
  vec3_t vsol = (vec3_t){-2, 0, 2};
  assert(equalsVec3(vRes, vsol));
}

void test_sub() {
  vec3_t v1 = (vec3_t){1, 2, 3};
  vec3_t v2 = (vec3_t){0, 0, 0};

  vec3_t vRes = subVec3(v1, v2);
  assert(equalsVec3(v1, vRes));

  v2 = (vec3_t){-3, -2, -1};
  vRes = subVec3(v1, v2);
  vec3_t vsol = (vec3_t){4, 4, 4};
  assert(equalsVec3(vRes, vsol));
}

void test_mul() {
  vec3_t v1 = (vec3_t){1, 2, 3};
  vec3_t vRes = mulVec3(v1, 0);
  vec3_t vSol = (vec3_t){0, 0, 0};
  assert(equalsVec3(vRes, vSol));

  vRes = mulVec3(v1, 2);
  vSol = (vec3_t){2, 4, 6};
  assert(equalsVec3(vRes, vSol));

  vRes = mulVec3(v1, -3);
  vSol = (vec3_t){-3, -6, -9};
  assert(equalsVec3(vRes, vSol));
}

void test_div() {
  vec3_t v1 = (vec3_t){6, 12, 18};
  vec3_t vRes = divVec3(v1, 2);
  vec3_t vSol = (vec3_t){3, 6, 9};
  assert(equalsVec3(vRes, vSol));

  vRes = divVec3(v1, 6);
  vSol = (vec3_t){1, 2, 3};
  assert(equalsVec3(vRes, vSol));

  vRes = divVec3(v1, 10);
  vSol = (vec3_t){0.6, 1.2, 1.8};
  assert(equalsVec3(vRes, vSol));

  vRes = divVec3(v1, 11);
  vSol = (vec3_t){6.0 / 11.0, 12.0 / 11.0, 18.0 / 11.0};
  assert(equalsVec3(vRes, vSol));
}

void test_dot() {
  vec3_t v1 = (vec3_t){1, 2, 3};
  vec3_t v2 = (vec3_t){4, 5, 6};

  assert(dotVec3(v1, v2) == (1 * 4 + 2 * 5 + 3 * 6));

  v1.x = -3;
  v1.y = 0;
  v2.x = 1;
  v2.z = 0;
  assert(dotVec3(v1, v2) == -3);
}

void test_cross() {
  vec3_t v1 = (vec3_t){1, 2, 3};
  vec3_t v2 = (vec3_t){4, 5, 6};
  vec3_t vRes = crossVec3(v1, v2);
  vec3_t vSol = (vec3_t){-3, 6, -3};
  assert(equalsVec3(vRes, vSol));

  v2 = (vec3_t){23, 12, 17};
  vRes = crossVec3(v1, v2);
  vSol = (vec3_t){-2, 52, -34};
  assert(equalsVec3(vRes, vSol));
}

void test_length() {
  vec3_t v1 = (vec3_t){23, 12, 17};
  assert(doubleEquals(lengthVec3(v1), sqrt(23 * 23 + 12 * 12 + 17 * 17)));

  v1 = (vec3_t){-20, 19, -13};
  assert(doubleEquals(lengthVec3(v1), sqrt(20 * 20 + 19 * 19 + 13 * 13)));
}

void test_normalize() {
  vec3_t v1 = (vec3_t){23, 12, 17};
  vec3_t vRes = normalizeVec3(v1);
  vec3_t vSol = {23.0 / sqrt(962), 12.0 / sqrt(962), 17.0 / sqrt(962)};
  assert(equalsVec3(vRes, vSol));
}

int main(void) {
  test_add();
  test_sub();
  test_mul();
  test_div();
  test_dot();
  test_cross();
  test_length();
  test_normalize();
  return 0;
}
