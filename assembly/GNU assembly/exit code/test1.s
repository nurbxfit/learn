# SIMPLE PROGRAM THAT RETURN STATUS CODE TO LINUX KERNEL.
# compile this using : as test1.s -o test1.o
# linking using: ld test1.o -o test1
# INPUT: none
# OUTPUT: status code. run: echo $?; at the terminal
# VARIABLES: %eax and %ebx
# %eax holds system call number
# %ebx holds return status.
# eax and ebx is a register that we use to store temporary data.
# data are stored in memory.
# checkout the .asm intel syntax version in x86 folder.

.section .data
.section .text
.global _start

_start:
    movl $1, %eax # moving linux syscall number for exit to eax
    movl $0, %ebx # return status 0 to operating system.

    int $0x80 # tell interup handler to tell linux kernel to run sys_exit.