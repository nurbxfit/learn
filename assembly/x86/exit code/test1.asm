; asm use intel syntax so it is different that GNU assembly syntax
; semicolon is a comments instead of hashtag
; checkout the GNU assembly version in GNU assembly folder
; compile using: nasm -f elf32 test1.asm -o test1.o
; link using: ld -m elf_i386 test1.o -o test1

section .text
    global _start

_start:
    mov eax, 1 ;moving linux syscall number for exit to eax
    mov ebx, 0 ;return status 0 to operating system.

    int 0x80   ;tell interup handler to tell linux kernel to run sys_exit.

; some resource recomends writing data section at the bottom but we can also write it at top with out .text section.

section .data

; in intel syntax data move from right to left
; in GNU assembly syntax, we move 1 from left to right.