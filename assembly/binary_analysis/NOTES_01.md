# Introduction
- there are two common techniques in binary analysis which are: statics analysis and dynamic analysis
- static: understanding the binary without running the program. but it do not have the knowledge of the program runtime state.
- dynamic: run the binary, able to know the runtime state and variables, but might miss other features in the source code,
	because we are focusing on the runtime code. 

- in binary analysis the, source code are stip into a machine code, thus removing the symbolic information of the code,
	such as variables name and symbols that are usefull in reading source code.
	instead information are stored in a binary inforamtion which sometimes represetable in hexadecimal format.
	- this means, no information such as data type of a declared variables, no high-level abstraction and no seperation between data and code.
	- tempering a single machine instruction on a binary can plasuibly result in the whole program to break.

# what is Binary ?
- computer is an electronic components which only understand the flow of electrical current in it.
- the flow of electrical current are represented in a binary format which 0 represent `off` or low current and 1 represents `on` or high current.
- when programmer writes program, the high-level human readable code are compiled and translated into a machine code, that form an intructions for a logic gate to operates.
- every programs when compiled, consist of binary code (machine instruction) and data (the variables and values it's holds).

# Program compilation process
- a compilation of a C or C++ programs consist of 4 main steps which is:
	- preprocessor process:
		- this process takes one or more source codes with their header files, stripping it down, removing commands and populated the macros (eg: #define, #include) with the content of it.
	- compilation process:
		- this process takes the preprocessed code and translate it into an assembly code. 
	- Assembly process:
		- this process takes the assembly code and generate machine code out of it. the machine code contains machine instructions, the output of this is an object file with `.o` extension. 
		- this object file contains machine instruction which in theory are executable, but not yet executable because it's still need to links the libraries that are included while writing the code
			with the library of the operating system.
		- if we had more than one `.c` source file in our program, it still need to be link together to form one executable files.

	- Linking process:
		- this process takes, the object files from previous process and link it together to form a one executable files.
		- this process also linked together libraries. most C programs use library that are precompiled in the operating system. as example in linux/unix based operating system,
			we can find these library in form of `.a` or `.so` format. the `.so` file can be found on `/lib/` folder in linux operating system.
			- the different of `.a` and `.so` is that `.a` is an archive library that are statically linked, means that any changes in the `.a` library files we need to compile and build our code again.
			- `.so` on the other hands are shared object that are dynamically linked during runtime. which we do not need to rebuild our whole project and only compile the `.so` if there is any changes in it.
			- but still we need to link our main program with the new `.so` file.

```c
#include <stdio.h>
#define FSTRING "%s"
#define MYSTRING "Hello World\n"

int main(int argc, char*argv[]){
	printf(FSTRING,MYSTRING);
	return 0;
}

```
here are an example of a simple hello world program written in .c programming language.
to see how this program get compiled we can use this command to compile it.
`gcc -E -P hello.c` the `-E` to tells gcc to stop 
