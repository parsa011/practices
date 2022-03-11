section .data
	SYS_WRITE  equ 1
	STD_IN	   equ 1
	SYS_EXIT   equ 60
	EXIT_CODE  equ 0

	NEW_LINE   db 0xa
	WRONG_ARGC db "Must to be two command line argument", 0

section .text
	global _start

_start :
	pop rcx			; get count of given args from command line, it should be 3 , one program name and 2 number
	cmp rcx, 3		; as we told argc should be 3
	jne _argc_error	; if compare failed , call argc_error

	add rsp, 8
	pop rsi
	call _str_to_int

	mov r10, rax
	pop rsi
	call _str_to_int
	mov r11, rax

	add r10, r11

_str_to_int :
	xor rax, rax
	mov rcx, 10

_next :
	cmp [rsi], byte 0  ; test rsi with 0, to check if we reached to end of string or no
	je _return_str 	   ; if rsi was 0, goto return
	mov bl, [rsi]      ; get a copy of rsi to bl
	sub bl, 48         ; bl - '0' to get int value for bl
	mul rcx
	add rax, rbx
	inc rsi
	jmp _next
	
_return_str :
	ret

_print :
	mov rax, 1
	mul r12
	mov r12, 8
	mul r12
	mov rdx, rax

	mov rax, SYS_WRITE
	mov rdi, STD_IN
	mov rsi, rsp
	syscall
	jmp _exit

_argc_error :
	mov rax, SYS_WRITE	; move write systemcall number into rax
	mov rdi, STD_IN		; set file descriptor to standard input fd
	mov rsi, WRONG_ARGC	; message that we want to show
	mov rdx, 34			; len of message
	syscall
	jmp _exit			; now we should close program

_exit :
	mov rax, SYS_EXIT
	mov rdi, EXIT_CODE
	syscall