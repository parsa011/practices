#ifndef clox_array_h
#define clox_array_h

#include "common.h"

typedef struct {
	int capacity;
	int count;
	int *values;
} IntArray;

void initIntArray(IntArray *array);
void writeIntArray(IntArray *array, int value);
void freeIntArray(IntArray *array);

#endif
