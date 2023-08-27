#include <stdio.h>
#include "global.h"
#include <string.h>

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

int parse_command_type(int *type, char *line)
{
	char c = *line;
	switch (c) {
		case '1' :
			*type = CREATE;
			break;
		case '2' :
			*type = TRANSFER;
			break;
		case '3' :
			*type = SHOW;
			break;
		default :
			*type = BAD_COMMAND;
			break;
	}
}

void parse_command_person_ip(struct person *person, char *line)
{
	while (*line) {
		person->ip[person->ip_len++] = *line++;
		if (*line == ':')
			break;
	}
	person->ip[person->ip_len] = '\0';
}

void parse_command_person_username(struct person *person, char *line)
{
	while (*line) {
		person->username[person->username_len++] = *line++;
		if (*line == ':')
			break;
	}
	person->username[person->username_len] = '\0';
}

void parse_command_person(struct person *person, char *line)
{
	char *ptr = line + 2;
	parse_command_person_ip(person, ptr);
	ptr++;
	parse_command_person_username(person, ptr);
	puts(person->username);
	
}

void parse_command(char *line)
{
	int type;
	parse_command_type(&type, line);
	struct person person;
	parse_command_person(&person, line);
}

int main()
{
	int len = 0;
	scanf("%d\n", &len);
	for (int i = 0; i < len; i++) {
		int line_len;
		char *line = read_line(&line_len);
		parse_command(line);
		free(line);
	}
	return 0;
}
