# Linux in General
- Linux kernel is based on a monolithic architecture.
  - it's a single binary system.
  - all of it's services run in kernel space.
  - a kernel is what provide a services for users to communicate with the hardware.
  - a kernel is actively sits in a seperate protected region of a memory of a computer when turned on, while other program get copied from the storage into the memory,
  and discarded when not needed.

- Simple anatomy of Linux Operating System.
  - A system running a Linux operating system consist of 3 layer.
    - User space layer.
    - Kernel Space Layer.
    - Hardware Layer.
  - User space layer program, communicate with Kernel space layer through system calls, or through the GNU C library.
  - Kernel space Layer then communicate with the hardware layer such as issuing interupt to the CPU.


# Linux Kernel
- A kernel is a manager that manage hardware resources to a running process. 
  - Linux kernel containts these 3 main components:
    - System libraries.
      - this containts the functions that application can use to interact with the kernel.
    - The Kernel Code.
      - this containts the core linux system code, that manage the networking and memory management.
    - Kernel Modules.
      - containts a dynamic kernel code, which can be load/unload during runtime.
  - though Linux kernel is a monolithic kernel, it's also modular, which can loads/unloads kernel modules at runtime.
  - in a linux system, we use `modprobe` command to load/unload a kernel modules during runtime.
  - to list all of loaded kernel, we use `lsmod` command.
  - the command basically list the contents of the /proc/modules in a nicely formatted list.
  - the results of `lsmod` command shows:
    - the name of kernel modules
    - the amount of memory that the module uses.
    - the sum (total) number of process that are using and depends on the module.
  - to see the kernel module information we use `modinfo` command. 
  - a hardware driver is a kernel module, which can be found in `/lib/modules/(yourkernel)/kernel/drivers/`
- The kernel runs in a kernel mode, which has unrestricted access to the hardware such as processor and main memory.
  - the user process on the other hands, run in user mode, which is a restricted space. 
  - this security layer between user process and a kernel is called a Protection Ring. 
  - where at ring 0, is the core kernel with the unrestricted privileged.
  - where at outmost layer, ring 3 is the user space, which is whit the lowest privilege, that can only modify/read a subset of the system.

# Importance of Main Memory (RAM) to a system.
- Main memory is the place where the kernel sit (get loaded), when a system turned on.
- it is just a storage of 1 and 0s, where the process later refer, to perform any operation.
- When a kernel get loaded into the main memory. The kernel then perform it's operation such as:
  - managing memory; spliting and dividing it to a process that needs it.
  - managing which memory region belongs to which process, and the sharing of memory between process.
  - managing CPU resources for each process: which process are allowed to use the CPU at given time.
  - managing the I/O devices, a kernel acts as a interface between hardware and processes. 
