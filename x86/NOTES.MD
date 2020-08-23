 # Introduction
- x86 is 32-bit little-endian architecture based on Intel 8086 processor.
- it's operates on two modes: real and protected.
- real modes support only 16-bits instruction set. 
- protected mode support virtual memory,paging and other features.
- x86 support concept of privilege seperation throuh `ring level` also known as protection ring abstraction.
- there are 4 ring level (0-3):
 	- ring0 is the highest privilege, that can modify all system settings.
	- ring3 is the lowest that can only modify/read a subset of system settings.
	- when least privilege level try to access higher privilege component. a system protection fault exception get thrown. 
- Most operating system make use of kernel privilege seperation which consit of, user level and kernel level.
- In OS kernel, user level mostly operates on level 3 of CPU protection ring.
- Kernel level on the other hands operates on level 0. 
- So when you are able to exploit a kernel to run a code, you basically are able to control the whole system.
- In intel IA-32 Architecture, there are 10x 32-bit and 16-bit register inside the processor. 
- the register are devided into three groups:
	- General Registers (General Purpose Register):
		- general register can be future devide into another 3 groups:
			- Data register, eg: EAX,EBX,ECX,EDX
			- Pointer Register, eg: IP, SP, BP 
			- Index Register, eg: SI, DI, 
	- Control Registers,
		- Control Register is the combination of 32-bit IP register and a 32-bit flags register.
		- Control register is what that holds flags value as bits, to indicate the status of an event. eg: overflow(OF), carry(CF), Interrupt(IF).
	- Segment Registers,
		- Segment registers holds the data, code and stack of a program.
		- Code Segment (CS) register holds the instruction that are going to be executed.
		- 16-bit CS register holds the starting address of the code segment.
			- then an 16-bit IP register, will use that information to percisely point to the (ofset) actual running instruction. 
		- Data segment (DS) register holds the data and constants declared in the code.
		- stack segment (SS) register holds the stack. (the location area/segment where the memory is to be use for the stack).
			- then an 16-bit SP register will use that information to point to the perciese location on the stack segment.
		- In assembly, a program need to know the location inside the memory. each location inside memory are devided into segments.
		- segment register holds, the starting address of these segments as the location of the segment.
		- to percisely locate the instruction and data inside the segment, register like IP and SP are used to calculate the ofset/percise location inside the segments.
		- imagine a a segment register holds, the address of a hotel building, IP and SP then holds the address of a room inside the building.

# Assembly programs layout.
- an assembly programs are devided into 3 segments or sections. 
	- .bss , contains the uninitialized  static data and global data that are declared in the code but not initialized. 
	- .text, contains the the instructions code of our programs.
	- .data, contains the dynamic initialized static data and global data that are declared.

- example of simple 'hello world' programs in assembly code.
```assembly
	section .text
		global _start
	
	_start:
		mov eax, 4 					; this tells to move linux system call for (sys_write) '4', into eax register
		mov ebx, 1 					; this tells to move linux (std_out) file descriptor to ebx that holds the first params for our sys_write in eax.
		mov ecx, mytext			; this tells to move mytext as the second params for sys_write in eax
		mov edx, mytext_len	; this tells to move mytext_len as the third params for sys_write in eax. 
												; note that after executed, return value of sys_write will populate the eax register.
												; means that value of eax register will be updated to whatever return value of the sys_write syscall.
		int 0x80						; here we just called an interup handler, 0x80 is the interup number for system kernel, that will handle the interupt to call the sys_write function. 
		
		mov eax, 0x1 				; here we call the sys_exit syscall to exit from sys_write and close all the open file descriptor in it.
		int 0x80 						; here we again called the interup handler to tell the kernel to run sys_exit.

	section .data
	mytext db 'Hello World',0xa ; this declare a new bytes variable called mytex contains the string 'hello world',
															; 0xa is the hex equivalent to 10 in decimal, in ascii encoding, number 10 is also known as '\n' characters.
	mytext_len equ $-mytext ; this tells to store the length of mytext into variable called mytext_len

```
- then we can assemble our assembly code using nasm assembler
- command: nasm -f elf32 -o hello.o hello.asm
- and then link it into executable file using ld
- command: ld -m elf_i386 -o hello hello.o
