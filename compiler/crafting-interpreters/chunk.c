#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk)
{
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
	initValueArray(&chunk->constants);
	initValueArray(&chunk->lines);
}

void freeChunk(Chunk *chunk)
{
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(Value, chunk->lines.values, chunk->capacity);
	freeValueArray(&chunk->constants);
	initChunk(chunk);
}

static void addLine(Chunk *chunk, int line)
{
	writeValueArray(&chunk->lines, line);
	writeValueArray(&chunk->lines, 1);
}

/*
 * ['line, count' , 'line, count']
 */
static void insertLine(Chunk *chunk, int line)
{
	if (chunk->lines.count == 0) {
		addLine(chunk, line);
	} else {
		if (line == chunk->lines.values[chunk->lines.count - 2]) {
			chunk->lines.values[chunk->lines.count - 1]++;
		} else {
			addLine(chunk, line);
		}
	}
}

void writeChunk(Chunk *chunk, uint8_t byte, int line)
{
	if (chunk->capacity < chunk->count + 1) {
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
	}
	if (chunk->lines.capacity < chunk->lines.count + 1) {
		int oldCapacity = chunk->lines.capacity;
		chunk->lines.capacity = GROW_CAPACITY(oldCapacity);
		chunk->lines.values = GROW_ARRAY(Value, chunk->lines.values,
										 oldCapacity, chunk->lines.capacity);
	}
	chunk->code[chunk->count] = byte;
	insertLine(chunk, line);
	chunk->count++;
}

int getLine(Chunk *chunk, int op_index)
{
	int n = 0;
	for (int i = 0; i < chunk->lines.count;) {
		n += chunk->lines.values[i + 1];
		if (n > op_index)
			return chunk->lines.values[i];
		i += 2;
	}
	return -1;
}

int addConstant(Chunk *chunk, Value value)
{
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
}
