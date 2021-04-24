# Learning Assembly and System Programming

### Linux Kernel.
- Linux OS, is a GNU Operating system. it's a operating system that consist of a Linux Kernel (open source version of Unix Kernel), and a GNU tools set and other Open source software.
- Kernel, functions as a manager of everything. it manages programs(a software) access to the hardware underneath.
- Kernel, helps ease the problem of having to write a low level program to communicate with the hardware by providing an abstract layer for programmer.
- without a Kernel, every programmer need to write different code entirely for different hardware model.
- when we write something on our keyboard. the hadware sends electrical signal to the other hardware where the kernel sits in. the kernel (that manage all hardware), receive a signal from the keyboard in form of [scancodes](https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html).
- the kernel than translate the information and pass the output to needed program.
- A machine only understand electrical signal, and the level of that signal (low/high) is encoded into a number 1 or 0 (binary). In short, a machine understand a binary arithmatics.
- some sequence of number can indicate certain operations in the system.
- Having to deal with numbers can be a hassel, thus computer scientist represent some of the operation with a mnemonics letters forming what we call the [assembly language](https://techterms.com/definition/assembly_language).


### Computer Architecture.
- Modern Computer is based on a [Von Neumann architecure](https://vivadifferences.com/5-major-difference-between-von-neumann-and-harvard-architecture/).
- that consist of the Central Processing Unit (CPU), and the Memory.
- A computer is basically a computing machine, that perform arithmatic.
- it takes data from an input devices, and manipulate it with help of memory to store and moving data, imagine memory as common math exercise book, consist of grid of boxes that we write numbers in it.
![math sheet](./pics/mathSheet.jpg "Grid boxes in math exercise book")
- each boxes have their own location address that we can get the position.
- in context of the math books, we can get the address of a box by using the plane system by finding it's location in x and y-axis.
- we can look a smaller box as a bit and a group of 4 small box is like a bytes. and we can come out with a new address of the big box.
- having the address of the big box, we can future devide it to get the address of the smaller box.
- all information are stored in memory. not only the program data, but also the program itself.
- a program is basically a set of instructions to perform operations.


### CPU.
- a CPU typically, consist of
    - Program Counter
    - Instruction Decoder
    - Data bus
    - General Purpose Registers
    - Arithmetic and Logic Unit.

### CPU Instruction.
- an instruction consist of a `operation code` (opcode) and `operands`
- `opcode` is mnemonics for operations such as `LOAD`, `MOVE`, `ADD`, `STORE`.
- when we want to tell a machine to add something, we use the `ADD` operation, which takes two `operands`.
```assembly
ADD R0, R2,R3 ; this is example of add operation,
          ; it takes R0, R2 and R3 as its operands
```
- what it means is that we add something from `R3` with `R2` and store it into `R0`
- operands is basically a data like an arguments to ADD function.
- we can pass these data to CPU via few different ways.
- ways CPU accessing data, is called [addressing modes](https://binaryterms.com/addressing-modes-and-its-types.html).
- thare are diffrents addressing modes such as:
    - `immediate mode`; actual/immediate data are given.
    - `register addressing mode`; a register contains actual value.
    - `indexed addressing mode`; a register contains address of value in CPU memory.
    - `direct addressing mode` ; an address of value located in CPU memory.
- these addressing modes, indicates whether data is passed directly or indirectly via reference pointing to memory address or a register holding a value.


## Outline of Assembly Program.
- anything start with a dot (.) is called a assembler directives or pseudo-operator.
- it is not an CPU instruction, instead something telling the assembler what to do with this information.
- we can see this as the preprocessor directives in C/C++ program that tells compiler what to do with the information when compiling.

    ### .(d0t)section
    - tells the assembler to divide our program into sections or segments.
    - each sections contains specific types of data.
    - if we see our object file, using `objdump` we can see the seperation.
    - most simple assembly program are divide into two sections.
    - `.data` or `.bss`; store static data for the program.
    - `.text`; contains instruction codes.
    ![objdump example](./pics/objdump.png "objdump example")
    - example running `objdump -D hello.o` ;
    - you can find `hello.o` in folder `x86/Hello/hello.o`.

    ### under the .section .text
    - we can see the starting our our instruction code.
    ```assembly
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
    # edx : third argument# hashtag is a comments
    ```
    - we can see `.global _start`, which tells the assembler, that _start is the symbol to label the location for our code.
    - we can write another function with label _myfunct, then _myfunct is a label to the location of our function instructions. 
    - `.global` means that the assembler shouldn’t discard this symbol after assembly.
    - `_start` are usually marked with `.global` to indicate the starting point of our program.
    - it's like the main function in c/c++.
    - then we see the `_start:` which defines our label.


    

