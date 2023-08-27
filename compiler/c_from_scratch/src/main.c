#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

int main(int argc, char *argv[]) {
  int res = compile_file("./test.c", "./test", 0);
  if (res == COMPILER_FILE_COMPILED_OK) {
    printf("everything compiled fine\n");
  } else if (res == COMPILER_FAILED_WITH_ERRORS) {
    printf("Compile failed\n");
  } else
    printf("Unknown response for compile file\n");
  return 0;
}
