#include "snekstack.h"
#include <stdlib.h>
#include "bootlib.h"

stack_t *stack_new(size_t capacity) {
  stack_t *new_stack = malloc(sizeof(stack_t));
  if (new_stack == NULL){
    return NULL;
  }
  new_stack->count = 0;
  new_stack->capacity = capacity;
  new_stack->data = malloc(sizeof(void *) * capacity);
  if (new_stack->data == NULL){
    return NULL;
  }
  return new_stack;
}
