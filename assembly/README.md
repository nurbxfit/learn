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
