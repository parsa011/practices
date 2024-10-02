#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

struct stack_t
{
	int *arr;
	int size;
	int index;
};

struct stack_t *init_stack(int max_size)
{
	struct stack_t *stack = (struct stack_t *) malloc(sizeof(struct stack_t));
	assert(stack);
	stack->arr = (int *) malloc(sizeof(int) * max_size);
	assert(stack->arr);
	memset(stack->arr, 0, sizeof(int) * max_size);
	stack->size = max_size;
	stack->index = 0;
	return stack;
}

void stack_push(struct stack_t *stack, int c)
{
	if (stack->index == stack->size)
	{
		cout << "[ERROR] : stack is full" << endl;
		return;
	}
	*(stack->arr + stack->index++) = c;
}

void stack_print(struct stack_t *stack)
{
	cout << "Size : " << stack->size << endl;
	cout << "Elements : " << stack->index << endl;
	for (int i = 0; i < stack->size; i++)
	{
		cout << *(stack->arr + i) << "   ";
	}
	cout << endl;
}

bool stack_pop(struct stack_t *stack, int *res)
{
	if (stack->index == 0)
	{
		return false;
	}
	return *(stack->arr + --stack->index);
}

string read_line()
{
	string str = "";
	char ch;
	while (true)
	{
		ch = getchar();
		if (ch == '\n')
			break;
		str += ch;
	}
	return str;
}

int get_int()
{
	char ch;
	int res = 0;
	while (true)
	{
		ch = getchar();
		if (ch == '\n')
			break;
		if (!isdigit(ch))
			continue;
		res = res * 10 + (ch - '0');
	}
	return res;
}

void stack_reset(struct stack_t *stack)
{
	memset(stack->arr, 0, sizeof(int) * stack->size);
	stack->index = 0;
}

int main()
{
	string str = {};
	struct stack_t *stack = init_stack(10);
	int c;
	bool temp;
	while (true)
	{
		cout << ">>> ";
		str = read_line();
		if (str == "exit")
			break;
		else if (str == "push")
		{
			c = get_int();
			stack_push(stack, c);
		}
		else if (str == "pop")
		{
			temp = stack_pop(stack, &c);
			if (!temp)
			{
				cout << "stack is empty" << endl;
				continue;
			}
			cout << c << endl;
		}
		else if (str == "print")
		{
			stack_print(stack);
		}
		else if (str == "reset")
		{
			stack_reset(stack);
		}
		else
		{
			cout << "Command Not Found" << endl;
		}
	}
	return 0;
}
