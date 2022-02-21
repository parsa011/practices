CC=cc
CFLAGS=-I.
DEPS = tint.h lexer.h file.h token.h
OBJ = main.o lexer.o file.o token.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tint: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
