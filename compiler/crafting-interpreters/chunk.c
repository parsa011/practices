#include "chunk.h"
#include "memory.h"

#include <stdlib.h>
#include <stdio.h>

void initChunk(Chunk *chunk)
{
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
	chunk->lines = NULL;
	initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk)
{
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(int, chunk->lines, chunk->capacity);
	freeValueArray(&chunk->constants);
	initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line)
{
	if (chunk->capacity < chunk->count + 1) {
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
		chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
	}
	chunk->lines[chunk->count] = line;
	chunk->code[chunk->count++] = byte;
}

int getLine(Chunk *chunk, int index)
{
	int line = -1;
	for (int j = 0, i = 0; j <= index; i += 2) {
		line = chunk->lines[i + 1];
		j += chunk->lines[i]; 
	}
	return line;
}

int addConstant(Chunk* chunk, Value value) 
{
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
}
