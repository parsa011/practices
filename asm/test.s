section .text
	global _start 
_start:
	mov ecx, len
	mov esi, s1
	mov edi, s2

	cld       ; redundant because DF is already guaranteed to be 0 on function entry
	; but included for illustration purposes

	loop_here:
	lodsb                ; AL=[esi],  ESI+=1 (because DF=0, otherwise ESI-=1)
	add al, 01
	stosb                ; [edi]=AL,  EDI+=1 (because DF=0, otherwise EDI-=1)
	loop loop_here       ; like dec ecx / jnz but without setting flags
	; ECX=0, EDI and ESI pointing to the end of their buffers

	mov edx, len-1       ;message length, not including the terminating 0 byte
	mov ecx,s2           ;message to write
	mov ebx,1            ;file descriptor (stdout)
	mov eax,4            ;system call number (sys_write)
	int 0x80             ;call kernel

	mov  eax,1           ;system call number (sys_exit)
	xor  ebx,ebx
	int  0x80            ;call kernel: sys_exit(0)

section .data
	s1: db 'password', 0        ; source buffer
	len equ $-s1

section .bss
	s2: resb len                ; destination buffer
