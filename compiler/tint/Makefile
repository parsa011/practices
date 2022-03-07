CC=cc
CFLAGS=-I.
DEPS = tint.h lexer.h file.h token.h ast.h parser.h statements.h
OBJ = main.o lexer.o file.o token.c ast.c parser.c statements.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tint: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test : tint
	./tint test/input1
