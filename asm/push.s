section data
	log_format db "%d\n"

section text
	global _start

_start :
	push 20
	pop r8
	call _print

_print :
	mov rdx, 1  ; set rdx to set , the write syscall number
	mov rdi, 1 	; store destination file descriptor int rdi, STDOUT
	mov rsi, log_format
	mov rdx, 1
	mov rcx, r8	
	extern printf
	call printf
	call _end

_end :
	mov rdx, 60
	mov rdi, 1
	syscall 