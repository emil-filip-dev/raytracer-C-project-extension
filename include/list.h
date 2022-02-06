#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

/*
 * An unordered list of pointers to memory-allocated values.
 */

typedef struct ListElem {
  void *value;
  struct ListElem *next;
} list_elem_t;

typedef struct list {
  list_elem_t *head;
  list_elem_t *curr;
  int length;
} list_t;

/*
 * A function which handles the freeing of objects in a list.
 */
typedef void (*val_free_func)(void *);

/*
 * Allocates a new list on the heap and returns a pointer to it.
 * Returns NULL if the allocation failed.
 */
list_t *newList();

/*
 * Destroys a list, freeing it from memory.
 *
 * val_free - If null, the elements of the list are not freed.
 *            This can cause a memory leak if used incorrectly.
 *            If non-null, the function is applied to each of the elements of
 *            the list in turn before the list itself is freed.
 */
void freeList(list_t *l, val_free_func val_free);

/*
 * Adds a pointer to the list.
 */
void listAdd(list_t *l, void *val);

/*
 * Returns an arbitrary element from the list.
 */
void *listHead(list_t *l);

/*
 * Returns the length of the list.
 */
int listLength(list_t *l);

/*
 * List iterator.
 *
 * Return value is NULL if the end of the list has been reached.
 *
 * l - If not null, the returned value is a pointer to the head of the list.
 *     If null, the returned value is a pointer to the next element in the
 *     previously specified list.
 */
void *listIterate(list_t *l);

void *listInterateReentrant(list_t *l, list_elem_t **le_ptr);

#endif  // __LIST_H__
