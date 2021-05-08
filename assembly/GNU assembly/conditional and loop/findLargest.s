# THIS PROGRAM FIND THE LARGEST NUMBER IN LIST OF NUMBERS.
# VARIABLES:
#   edi - store index of data being examined/compare.
#   ebx - store largest data item found.
#   eax - store current data item
#   data - contains list of numbers.
# run:
# - as findLargest.s -o findLargest.o
# - ld findLargest.o -o findLargest
# - ./findLargest
# - echo $?

.section .text

.global _start
_start:
    movl $0, %edi #mov 0 into index register (first index a.k.a first item)
    movl data_items(,%edi,4), %eax #store item at first index of data_items to %eax
    movl %eax, %ebx #set first item as the biggest.

start_loop: #label for starting point of our loop
    cmpl $0,%eax #check if we reach the end of our list(because last item is 0)
    je loop_exit #if reach 0, then we jump to exit label.
    incl %edi #increment index (like i++), point to next 4 byte
    movl data_items(,%edi,4), %eax #store second item to %eax; 4 is the size of data because we declared as long
    cmpl %ebx, %eax #compare current item with stored largest item.
    jle start_loop # if less then we mov to other index
    movl %eax,%ebx # else if bigger, we store that in %ebx
    jmp start_loop # repeat the process until we reach the last item (0).

loop_exit:
    movl $1, %eax # $1 is exit() syscall
    int $0x80 #call interupt


.section .data
data_items: 
    .long 2,3,1,99,125,33,21,255,11,0 # this is the list of numbers