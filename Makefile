all : tokenizer.o
	gcc tokenizer.c

asm :
	nasm -f elf64 -o asm.o asm.s
	ld -o asm asm.o
	rm asm.o

clean :
	rm ./a.out ./asm ./asm.o
