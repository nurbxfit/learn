Note from learning Unix system programming.

# System call

## Basic Operating system work.

- operating system devides hardware resources to applications by providing them with providing an `application programming interface (API)`.
- the API published enable applications to call operating system functions to access underlining hardware resources.
- like the web API concept where we publish an API point that a front-end application can send request and get back data processed by the Back-end.
- all the heavy process of information are handled by operating systems.
- like an example, a POSIX like system provide access to hardrive thru `read()` and `write()` API on a file descriptor.
- these `API` make calls to the operating system using `application binary interface (ABI)` called system call.
- these system call then return a file descriptor for the programmer to write and read from the hard drives.
- the act of making use of syscall to perform a task is called `system programming`.

## Anatomy of Syscall.

- an x86 cpu, make use of interupts to provide system call.
- in my `assembly folder`, we learn that thru assembly, we can move data into specific register and then make system call by issueing interrupt to the CPU.
- in that tutorial we issue the `int $0x80` interupt to triggered kernel to invoke system call.

```
An interrupt is a signal to the operating system that an event has occurred, and it results in changes in the sequence of instructions executed by the CPU. There are numerous sources of interrupts, including pressing a key on keyboard, moving the mouse, timers, disk drives, signals originating elsewhere on the network and the loss of electrical power. A software interrupt is an interrupt that originates in software, usually by a process in user mode.

- from: http://www.linfo.org/int_0x80.html
```

- an application can read data from hard disk using system BIOS by using the`0x13` interupt.

- the register layout is

```
AH = 2
AL: Sectors to read
CH: Cylinder
CL: Sector
DH: Head
DL: Drive
ES:BX: Buffer address
```

- the Buffer address is the memory address that will store the information we trying to read at the specific location we provided.
- `Sectors to read, cylinder,sector,head,drive` these information indicate the location where to specificly read the information.
- the system call will read from that location and add it to buffer.
- after finish reading BIOS will then execute the `iret` (interupt return) to return the the application.
- the application can use the buffer to get the content of the hard drive.
- this approach of calling system call using interupt have their drawback which is slowing down the operating system as the CPU need to stop current task, save CPU state and perfom the syscall.
- most modern intel x86 CPU make use of `fast system call` instructions which are defsigned to overcome this issue.
- this `fast syscall` allow operating system to execute system call without having to save the entire CPU state, before begin executing syscall.
- constanly invoking syscall can be a huge down performance to the operating system, so it is advisesable to minimal the calling of syscall when developing application.

## Requesting for Memory.

- when a program get execute, they are given `global memory`, `stack memory` and a small portion of `heap memory` when the application use API like `malloc()` and `free()`.
- if the allocated heap memory run out during runtime, the `malloc()` will have to ask the operating system to allocate more memory via system call.
- is the system have no extra memory in RAM. operating systemm will have to allocate memory from another application that are currently not using the memory.
- the operating system will swap that another application into hard disk memory and give the memory region of that application to current application that need it.
- this behaviour is expensive to do.

## Meltdown and Spectre

- to support fast excution of syscall. the kernel's memory is mapped into each application using memory layout called `3:1 split`. `3 application memory: 1 kernel memory`.
- modern CPU provide mechanism to lock-down kernel portion of the memory from any attempt to access it by other applications.
- applications only able to see the deprivileged portion of that memory.
- modern CPU use `speculative execution` to improve the performance.
- `speculative execution` is when an instruction speculate the state of a variable.

```
if(x) {
    do_y();
}
do_x();
```

- let say this statement get runs multiple times, and it always result with x is false.
- modern CPU will speculate the result of x to be `false` next time it reach the instruction in order to improve the speed.
-
