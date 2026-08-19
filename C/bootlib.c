#define BOOTLIB_NO_OVERRIDE
#include "bootlib.h"

#include <stdlib.h>

// Tracks every live (not-yet-freed) allocation made through boot_malloc()
// so boot_all_freed() and boot_alloc_size() can report on them.

typedef struct boot_alloc {
  void *ptr;
  size_t size;
  struct boot_alloc *next;
} boot_alloc_t;

static boot_alloc_t *allocations = NULL;
static size_t outstanding_bytes = 0;

void *boot_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }

  boot_alloc_t *node = malloc(sizeof(boot_alloc_t));
  if (node != NULL) {
    node->ptr = ptr;
    node->size = size;
    node->next = allocations;
    allocations = node;
    outstanding_bytes += size;
  }

  return ptr;
}

void boot_free(void *ptr) {
  if (ptr == NULL) {
    return;
  }

  boot_alloc_t **cur = &allocations;
  while (*cur != NULL) {
    if ((*cur)->ptr == ptr) {
      boot_alloc_t *found = *cur;
      outstanding_bytes -= found->size;
      *cur = found->next;
      free(found);
      break;
    }
    cur = &(*cur)->next;
  }

  free(ptr);
}

bool boot_all_freed(void) {
  return allocations == NULL;
}

size_t boot_alloc_size(void) {
  return outstanding_bytes;
}
