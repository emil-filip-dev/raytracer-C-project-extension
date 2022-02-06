#include "../include/list.h"

#include <assert.h>

void testNew(void) {
  list_t *l = newList();
  assert(l != NULL);
  assert(listHead(l) == NULL);
  assert(listLength(l) == 0);
  free(l);
}

void testDestroy(void) {
  list_t *l = newList();
  freeList(l, NULL);
}

void testAdd(void) {
  int x, y, z;
  x = 1;
  y = 2;
  z = 3;

  list_t *l = newList();

  listAdd(l, &x);
  assert(listLength(l) == 1);
  listAdd(l, &y);
  assert(listLength(l) == 2);
  listAdd(l, &z);
  assert(listLength(l) == 3);

  freeList(l, NULL);
}

void testIterate(void) {
  int x, y, z;
  x = 1;
  y = 2;
  z = 3;

  list_t *l = newList();
  listAdd(l, &x);
  listAdd(l, &y);
  listAdd(l, &z);

  int sum = 0;
  for (void *v = listIterate(l); v != NULL; v = listIterate(NULL)) {
    sum += *(int *)v;
  }

  assert(sum == x + y + z);

  freeList(l, NULL);
}

void testIterateReentrant(void) {
  int x, y, z;
  x = 1;
  y = 2;
  z = 3;

  list_t *l = newList();
  listAdd(l, &x);
  listAdd(l, &y);
  listAdd(l, &z);

  int sum = 0;
  list_elem_t *le_ptr;
  for (void *v = listInterateReentrant(l, &le_ptr); v != NULL;
       v = listInterateReentrant(NULL, &le_ptr)) {
    sum += *(int *)v;
  }

  assert(sum == x + y + z);

  freeList(l, NULL);
}

int main(void) {
  testNew();
  testDestroy();
  testAdd();
  testIterate();
  testIterateReentrant();
  return EXIT_SUCCESS;
}
