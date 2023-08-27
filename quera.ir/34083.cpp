#include <stdio.h>
#include "global.h"

#define USER_NAME_MAX_LEN 128
#define IP_MAX_LEN 128

enum command_type {
	CREATE,
	TRANSFER,
	SHOW,
	BAD_COMMAND
};

struct person {
	char username[USER_NAME_MAX_LEN];
	int username_len;
	char ip[IP_MAX_LEN];
	int ip_len;

	int money; 
};

struct person_input {
	struct person person;
	short type;
	int money;
};

int parse_command_type(char *line)
{
	char type = *line;
	printf("command is %c\n", type);
	switch (type) {
		case '1' :
			return CREATE;
		case '2' :
			return TRANSFER;
		case '3' :
			return SHOW;
		default :
			return BAD_COMMAND;
	}
}

void parse_command(char *line)
{
	int type = parse_command_type(line);
}

int main()
{
	int len = 0;
	scanf("%d\n", &len);
	for (int i = 0; i < len; i++) {
		int line_len;
		char *line = read_line(&line_len);
	}
	return 0;
}
