# THIS example find the smallest number in list of numbers.
# VARIABLE:
#   edi - store index of data being examined/compare.
#   ebx - store smallest data item found.
#   eax - store current data item
#   data - contains list of numbers.
# run:
# - as findSmall.s -o findSmall.o
# - ld findSmall.o -o findSmall
# - ./findSmall
# - echo $?

.section .text

.global _start
_start:
    movl $0, %edi
    movl data_items(,%edi,4), %eax
    movl %eax, %ebx 

start_loop:
    cmpl $10,%edi
    je loop_exit
    incl %edi
    movl data_items(,%edi,4),%eax
    cmpl %ebx , %eax
    jge start_loop
    movl %eax,%ebx #else if small, we store it in ebx
    jmp start_loop

loop_exit:
    movl $1, %eax # $1 is exit() syscall
    int $0x80 #call interupt

.section .data
data_items: 
    .long 2,3,1,99,125,33,21,255,11,0 # this is the list of numbers (10 x 4)
    len = .- data_items # length of our string