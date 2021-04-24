# hashtag is a comments
# INPUT: none
# OUTPUT : Hello World
# VARIABLES: eax, ebx, ecx ,edx
# checkout intel syntax version in x86 folder.


.section .text
.global _start

_start:
    movl $4, %eax       # mov linux sys_write(4) syscall number to eax.
    movl $1, %ebx       # mov file handler (stdout) to ebx (first argument)
    movl $message, %ecx # mov our message to ecx (second argument)
    movl $len, %edx     # mov message length to edx (third argument)
    int $0x80            # call kernel interupt and exit.

    movl $0, %ebx       #return exit code 0 to kernel.
    movl $1, %eax       # mov syscall for sys_exit(1) to eax.

    int $0x80            #call kernel interupt and run sys_exit
.section .data
message:
    .ascii "Hello World\n" # our output string
    len = .- message # length of our string



# simple note:
# eax : syscall 
# ebx : first argument
# ecx : second argument
# edx : third argument