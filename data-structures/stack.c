#include <stdio.h>
#include <stdlib.h>

struct stack {
	int *data;
	int top;
	int size;
};

void stack_init(struct stack *s, int size)
{
	s->data = (int *) malloc(sizeof(int) * size);
	s->size = size;
	s->top = 0;
}

void stack_push(struct stack *s, int val)
{
	if (s->top == s->size) {
		printf("Stack Is Full\n");
	} else {
		s->data[s->top++] = val;
	}
}

void stack_pop(struct stack *s, int *val)
{
	if (s->top == 0) {
		printf("Stack Is Empty\n");
	} else {
		*val = s->data[--s->top];
	}
}

int main()
{
	struct stack s;
	int temp = 0;
	stack_init(&s, 2);
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);

	printf("%d\n", temp);
	return 0;
}
