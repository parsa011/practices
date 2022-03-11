section .data
    SYS_WRITE equ 1
    STD_OUT   equ 1
    SYS_EXIT  equ 60
    EXIT_CODE equ 0

    NEW_LINE  db  0xa
    INPUT     db  "Hellow World!"

section .bss
    OUTPUT	  resb 12


section .text
    gloabl _start

_start :
    mov rsi, INPUT
    xor rcx, rcx
    cld
    mov rdi, $ + 15
    call _str_len
    xor rax, rax
    xor rdi, rdi
    jmp _str_reverse

_str_len :	; calculate length of string and store it in rcx
    cmp byte [rsi], 0 ; check is it end of string
    je _exit_func	  ; if yes exit from function
    lodsb			  ; load byte from rsi to al and inc rsi
    push rax		  ; push symbol to stack
    inc rcx			  ; increase counter
    jmp _str_len	  ; loop again

_exit_func :
    push rdi		  ; push  return addres stack again
    ret
