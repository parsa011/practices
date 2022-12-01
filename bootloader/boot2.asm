bits 16
org 0x7c00

boot :
	mov ax, 0x2401
	int 0x15					; enable A20 bit
	mov ax, 0x3
	int 0x10					; set vga text mode 3
	lgdt [gdt_pointer]
	mov eax, cr0
	or eax, 0x1					; set the protected mode bit on special CPU reg cr0
	mov cr0, eax
	jmp CODE_SET:boot2			; long jump to the code segment
	
	
