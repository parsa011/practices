#ifndef COMPILER_H
# define COMPILER_H

#include <stdio.h>
#include <stdbool.h>

struct pos {
  int line;
  int col;
  const char *filename;
};

enum {
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYPE_OPERATOR,
  TOKEN_TYPE_SYMBOL,
  TOKEN_TYPE,NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE
};

struct token {
  int type;
  int flags;

  // our token value can be differnet , it can be int, long, or pointer to anythere
  // we should guarantee that we will have one of them for tokens
  union {
    char cval;
    const char *sval;
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void *any;
  };

  // true if their is whitespace bewteen token and the next token
  // i.e * a for operator token * would mean whitepsace would be set for token "a"
  bool whitespace;

  const char *between_brackets;
};

enum
{
  COMPILER_FILE_COMPILED_OK,
  COMPILER_FAILED_WITH_ERRORS
};


struct lex_process;
typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process *process);
typedef char (*LEX_PROCESS_PEEK_CHAR)(struct lex_process *process);
typedef void (*LEX_PROCESS_PUSH_CHAR)(struct lex_process *process, char c);

struct lex_process_functions {
  LEX_PROCESS_NEXT_CHAR next_char;
  LEX_PROCESS_PEEK_CHAR peek_char;
  LEX_PROCESS_PUSH_CHAR push_char;
};

struct lex_process {
  struct pos pos;
  struct vector *token_vec;
  struct compile_process *compiler;

  int current_expression_count;

  struct buffer *parentheses_buffer;
  struct lex_process_functions *function;

  // this will be private data that the lexer does not understand
  // but the person using the lexer does understand
  void *private;
};

struct compile_process
{
  // the flags in regards to how this file should be compiled
  int flags;

  struct pos pos;
  struct compile_process_input_file {
    FILE *fp;
    const char *abs_path;
  } cfile;

  FILE *ofile;
};

int compile_file(const char *filename, const char *output_filename, int flags);
struct compile_process *compile_process_create(const char *filename, const char *filename_out, int flags);

char compile_process_next_char(struct lex_process *lex_process);
char compile_process_peek_char(struct lex_process *lex_process);
void compile_process_push_char(struct lex_process *lex_process, char c);

#endif
