; semicolon is a comments 
; hello.asm
; author: Nurfitri

section .text
	global _start

_start:
	mov eax, 4 
	mov ebx, 1
	mov ecx, mytext
	mov edx, mytext_len

	int 0x80

	mov eax, 0x1
	int 0x80

section .data
mytext db 'Hello World',0xa 
mytext_len equ $-mytext
