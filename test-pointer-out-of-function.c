#include <stdio.h>

typedef struct {
	char name[10];
} person;

person *give_me_pointer()
{
	person parsa;
	return &parsa;
}

int main(int argc, char **argv)
{
	printf("%p\n", give_me_pointer());
	return 0;
}
