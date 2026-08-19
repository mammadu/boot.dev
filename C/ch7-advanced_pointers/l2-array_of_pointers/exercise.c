#include "exercise.h"
#include <stdlib.h>

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
  token_t **token_pointers = malloc(count * sizeof(token_t *));
  if (token_pointers == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < count; ++i) {
    token_t *heap_token = (token_t *)malloc(sizeof(token_t));
    *heap_token = tokens[i];
    token_pointers[i] = heap_token;
  }
  return token_pointers;
}
