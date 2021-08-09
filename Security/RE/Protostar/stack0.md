```bash
gdb ./stack0
```
```bash
(gdb) set disassembly-flavor intel
```
- then we view main function disassembly
```
(gdb) disassemble main
Dump of assembler code for function main:
0x080483f4 <main+0>:	push   ebp
0x080483f5 <main+1>:	mov    ebp,esp
0x080483f7 <main+3>:	and    esp,0xfffffff0
0x080483fa <main+6>:	sub    esp,0x60
0x080483fd <main+9>:	mov    DWORD PTR [esp+0x5c],0x0
0x08048405 <main+17>:	lea    eax,[esp+0x1c]
0x08048409 <main+21>:	mov    DWORD PTR [esp],eax
0x0804840c <main+24>:	call   0x804830c <gets@plt>
0x08048411 <main+29>:	mov    eax,DWORD PTR [esp+0x5c]
0x08048415 <main+33>:	test   eax,eax
0x08048417 <main+35>:	je     0x8048427 <main+51>
0x08048419 <main+37>:	mov    DWORD PTR [esp],0x8048500
0x08048420 <main+44>:	call   0x804832c <puts@plt>
0x08048425 <main+49>:	jmp    0x8048433 <main+63>
0x08048427 <main+51>:	mov    DWORD PTR [esp],0x8048529
0x0804842e <main+58>:	call   0x804832c <puts@plt>
0x08048433 <main+63>:	leave  
0x08048434 <main+64>:	ret    
End of assembler dump.

```

- we set our first breakpoint to main
```
(gdb) break main
```
- this will set our breakpoint at main.
- then run the program
```
(gdb) run
```
- when our program stop at main. we can view register informaion using
```
(gdb) info registers
eax            0xbffff864	-1073743772
ecx            0x968a9a43	-1769301437
edx            0x1	1
ebx            0xb7fd7ff4	-1208123404
esp            0xbffff750	0xbffff750
ebp            0xbffff7b8	0xbffff7b8
esi            0x0	0
edi            0x0	0
eip            0x80483fd	0x80483fd <main+9>
eflags         0x200286	[ PF SF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
```
- here we see our instruction pointer register `(eip)` is at <main+9>.

- based on the dissabled code.
```asm
0x080483fd <main+9>:	mov    DWORD PTR [esp+0x5c],0x0
``` 
- look like a variable initialization.
- where we set it value to 0x0.
- its a local variable in our stack.
- our stack (esp) right now is 0xbffff750	0xbffff750
- we can indeed verify that it is initializing a variable to zero.
- we view our stack value using
```
(gdb) x/x 0xbffff750
0xbffff750:	0x00000000
```
- this show that the stack value at 0xbffff750 is 0x000000000
- which is a hex for 0.
- we can also use `x/d` to view the decimal value
```
(gdb) x/d 0xbffff750
0xbffff750:	0
```
- [x command reference](https://visualgdb.com/gdbreference/commands/x)
```
0x08048405 <main+17>:	lea    eax,[esp+0x1c]
```
- here the stack pointer move another 0x1c address.
- the size between the first variable that was initialized to 0 and this new variable is 0x5c - 0x1c = 0x40
- `0x40` is hex for decimal `64`.
- so the distance is `64`. 

```
0x08048411 <main+29>:	mov    eax,DWORD PTR [esp+0x5c]
0x08048415 <main+33>:	test   eax,eax
```
- here we see again, the first variable is being used
- the `test` instruction perform a bitwise logical `AND` operation, if the result of the AND operation is `0` it will set the `Zero Flag` in register to `1`. else it set the `Zero Flag` to `0`.
- the zero flag are then being used by the `jump` instruction.
```
0x08048417 <main+35>:	je     0x8048427 <main+51>
```
- this jump instruction check if the zero flag is set to `1`. 
- so if `eax=0`, then bitwise `eax & eax`, will be 0, and the Zero flag will be `1`, so the jump instruction get executed.
- if `eax=1`, then bitwise `eax & eax` will be 1. the zero flag will be `0`, so the jump instruction not get executed.

- there are few ways we can navigate:
    - `si` for step into instruction.
    - `ni` for next instruction.
    - if we use si, our instruction pointer will step into a function call.
    - if we don't want it, we can use `ni` instead.

- we can use `ni` multiple time until we reach 
```
0x0804840c <main+24>:	call   0x804830c <gets@plt>
```
- where the program as for user input using gets().
- the program will hang and ask for our input.
- we can input `AAAAAA`, and then use info register to check
- after that move again to the next instruction at
```
0x08048411 <main+29>:	mov    eax,DWORD PTR [esp+0x5c]
```
- here before this instruction get execute, inspect our registers.
```
(gdb) info register
eax            0xbffff76c	-1073744020
ecx            0xbffff76c	-1073744020
edx            0xb7fd9334	-1208118476
ebx            0xb7fd7ff4	-1208123404
esp            0xbffff750	0xbffff750
ebp            0xbffff7b8	0xbffff7b8
esi            0x0	0
edi            0x0	0
eip            0x8048411	0x8048411 <main+29>
eflags         0x200246	[ PF ZF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
```
- then we look at the value of our eax,
```
(gdb) x/s 0xbffff76c
0xbffff76c:	 "AAAAAA"
```
- eax contains the value of `AAAAAA` our previous input.
- the if go to next instruction, and look at register info.
```
(gdb) info register
eax            0x0	0
ecx            0xbffff76c	-1073744020
edx            0xb7fd9334	-1208118476
ebx            0xb7fd7ff4	-1208123404
esp            0xbffff750	0xbffff750
ebp            0xbffff7b8	0xbffff7b8
esi            0x0	0
edi            0x0	0
eip            0x8048415	0x8048415 <main+33>
eflags         0x200246	[ PF ZF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
(gdb) 
```
- our eax value is 0.
- this is because on previous instruction, we move the variable `DWORD PTR [esp+0x5c]` into our eax register.
- this is before we execute the `test` instruction.
- going to next instruction using `ni` until we past the `je` instruction.
- we noticed that the `jump` instruction get executed.
```
(gdb) info registers
eax            0x0	0
ecx            0xbffff76c	-1073744020
edx            0xb7fd9334	-1208118476
ebx            0xb7fd7ff4	-1208123404
esp            0xbffff750	0xbffff750
ebp            0xbffff7b8	0xbffff7b8
esi            0x0	0
edi            0x0	0
eip            0x8048427	0x8048427 <main+51>
eflags         0x200246	[ PF ZF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs 
```
- our instruction now at `0x8048427`, which means we jump few instruction ahead.
- this happen because our `eax` value is `0`.
- we see earlier that for the bitwise AND operator, if 0&0, the value will be 0. the test instruction then set the zero flag to `1`.
- when the zero flag is `1`. the jump instruction will execute. thus we are jumping.
- here the instruction is 
```
(gdb) x/i 0x8048427
0x8048427 <main+51>:	mov    DWORD PTR [esp],0x8048529
```
- we are moving the value at `0x8048529` into stack pointer.
- this is the string we are passing to the next instruction which is `puts`. 
- we can view this string using
```
(gdb) x/s 0x8048529
0x8048529:	 "Try again?"
```
- we noticed that the string going to be output is `"Try again?"`. means we are unable to break the program flow.

## What we noticed so far ?
- we noticed that our input never being used for the test instruction.
- instead the variable `DWORD PTR [esp+0x5c]` is being used.
- lets name this variable `VARA`.
- `VARA` at the beginning of the program is set to value 0.
- then another variable get declared, we noticed from these instruction. 
```
0x08048405 <main+17>:	lea    eax,[esp+0x1c]
0x08048409 <main+21>:	mov    DWORD PTR [esp],eax
```
- the size different of these two variable is `64`.
- we also noticed that 