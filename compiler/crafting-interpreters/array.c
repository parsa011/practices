#include "array.h"
#include "memory.h"

void initIntArray(IntArray *array)
{
	array->values = NULL;
	array->count = 0;
	array->capacity = 0;
}

void writeIntArray(IntArray *array, int value)
{
	if (array->capacity < array->count + 1) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->values = GROW_ARRAY(Value, array->values,
								   oldCapacity, array->capacity);
	}
	array->values[array->count] = value;
	array->count++;
}

void freeIntArray(IntArray* array)
{
	FREE_ARRAY(Value, array->values, array->capacity);
	initIntArray(array);
}
