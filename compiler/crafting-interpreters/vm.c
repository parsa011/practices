#include <stdio.h>
#include <stdarg.h>

#include "vm.h"
#include "common.h"
#include "compiler.h" 
#include "debug.h"

VM vm;

static void resetStack()
{
	vm.stackTop = vm.stack;
}

static void runtimeError(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	fputs("\n", stderr);
	
	size_t instruction = vm.ip - vm.chunk->code - 1;
	int line = vm.chunk->lines.values[instruction];
	fprintf(stderr, "[line %d] in script\n", line);
	
	resetStack();
}

void initVM()
{
	resetStack();
}

void freeVM()
{

}


void push(Value value)
{
	*vm.stackTop++ = value;
}

Value pop()
{
	return *(--vm.stackTop);
}

static Value peek(int distance)
{
	return vm.stackTop[-1 - distance];
}

static bool isFalsy(Value value)
{
	// numbers bigger than 0 are true, like c :) to much for a scripting language, right ?
	return (IS_NIL(value) || (IS_BOOL(value) && !AS_BOOL(value)))
		   ||
		(IS_NUMBER(value) && AS_NUMBER(value) < 0);
}

static InterpretResult run()
{
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(valueType, op)							\
	do {													\
		if (!IS_NUMBER(peek(0)) || !IS_NUMBER(peek(1))) {	\
			runtimeError("Operands must be numbers.");		\
			return INTERPRET_RUNTIME_ERROR;					\
		}													\
		Value b = pop();									\
		Value a = pop();									\
		push(valueType(AS_NUMBER(a) op AS_NUMBER(b)));		\
	} while (false);
	
	for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
		printf("          ");
		for (Value *slot = vm.stack; slot < vm.stackTop; slot++) {
			printf("[ ");
			printValue(*slot);
			printf(" ]");
		}
		printf("\n");
		disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
		uint8_t instruction;
		switch (instruction = READ_BYTE()) {
		case OP_CONSTANT : {
			Value constant = READ_CONSTANT();
			push(constant);
			break;
		}
		case OP_NIL :
			push(NIL_VAL);
			break;
		case OP_TRUE :
			push(BOOL_VAL(true));
			break;
		case OP_FALSE :
			push(BOOL_VAL(false));
			break;
		case OP_EQUAL : {
			Value a = pop();
			Value b = pop();
			push(BOOL_VAL(valuesEqual(a, b)));
			break;
		}
		case OP_GREATER :
			BINARY_OP(BOOL_VAL, >);
			break;
		case OP_LESS :
			BINARY_OP(BOOL_VAL, <);
			break;
		case OP_ADD :
			BINARY_OP(NUMBER_VAL, +);
			break;
		case OP_SUBTRACT :
			BINARY_OP(NUMBER_VAL, -);
			break;
		case OP_MULTIPLY :
			BINARY_OP(NUMBER_VAL, *);
			break;
		case OP_DIVIDE :
			BINARY_OP(NUMBER_VAL, /);
			break;
		case OP_NOT :
			push(BOOL_VAL(isFalsy(pop())));
			break;
		case OP_NEGATE :
			if (!IS_NUMBER(peek(0))) {
				runtimeError("Operand must be a number.");
				return INTERPRET_RUNTIME_ERROR;
			}
			push(NUMBER_VAL(-AS_NUMBER(pop())));
			break;
		case OP_RETURN :
			printValue(pop());
			printf("\n");
			return INTERPRET_OK;
		}
	}
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

InterpretResult interpret(const char *source)
{
	Chunk chunk;
	initChunk(&chunk);
	if (!compile(source, &chunk)) {
		freeChunk(&chunk);
		return INTERPRET_COMPILE_ERROR;
	}
	vm.chunk = &chunk;
	vm.ip = vm.chunk->code;
	InterpretResult result = run();
	freeChunk(&chunk);
	return result;
}
