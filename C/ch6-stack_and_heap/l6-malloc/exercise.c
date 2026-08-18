#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_array(int size, int multiplier) {
  int *array = (int *)malloc(size * sizeof(int));
  if (array == NULL){
    return NULL;
  }
  for (int i = 0; i < size; i++){
    array[i] = i * multiplier;
  }
  return array;
}
