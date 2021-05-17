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

## Where is Linux Kernel ?

- in linux operatinf system,a kernel file can be found in the `/boot` directory named start with `vmlinuz`.
- we can check our kernel version using `uname -r`

# Importance of Main Memory (RAM) to a system.

- Main memory is the place where the kernel sit (get loaded), when a system turned on.
- it is just a storage of 1 and 0s, where the process later refer, to perform any operation.
- When a kernel get loaded into the main memory. The kernel then perform it's operation such as:
  - managing memory; spliting and dividing it to a process that needs it.
  - managing which memory region belongs to which process, and the sharing of memory between process.
  - managing CPU resources for each process: which process are allowed to use the CPU at given time.
  - managing the I/O devices, a kernel acts as a interface between hardware and processes.

# Usefull Linux system Command

- please use `man` command to get more information of these commands.

## Command to get hardware information.

- lshw
- lspci
- lsusb
- lsblk
- lscpu
- lsdev

## Command to configure hardware.

- hdparm
- echo to `/proc`, `/dev` or `/sys` files
- `inb` and `outb`
- setpci
- sysctl

# sysctl

- using sysctl we can view and manipulate kernel variable.
- kernel variables can also be found in `/proc/sys/` folder.
- we can list all kernel variable using `sysctl -a`
- to enable ip fowarding we can net.ipv4.ip_forward variable to 1.
  - `sysctl net.ipv4.ip_foward=1`

# When we run a Software.

- when we run a software or application, it's run in application layer.
- the application do not communicate directly with our kernel, instead communicate via the System library such as standart C library.
- this application, call the function in libraries which invoke kernel system call.
- we can see the function prototype of these systemcalll in
  - `/usr/src/linux-hwe-<ourkernelversion>/include/uapi/asm-generic/unistd.h`
- in my learn assembly guide, we can see that we are invoking a systemcall thru assembly by passing variables into registers, and then invoke an interupt to tell the linux kernel we want it to handle this event.
- the kernel then check the interupt number and handle the interupt, invoking the system call and it's parameters pass to the register.
- a system call will return `negative` value to caller library if an error happen.
- the library then will set global variable to `errno` and returns `-1` to application program invoking the library.
- in man page, system call are located in section 2.

  - we can view more info of syscall by using `man 2 <syscallname>`
  - eg: `man 2 exit`

- we can view list of system call get called by a program using the `strace <commandname>`.
  - let say we want to view strace of `echo` command.
  - we can use `strace echo`

# Reading message from kernel.

- [printk](https://elinux.org/Debugging_by_printing)
  - a kernel's function to print message from kernel. (like `printf` in c).
  - we use printk to send kernel message to other place like RAM buffer, system console, or a logging deamon.
  - I think, the weird writing we see during boot up of our linux machine is produced by `printk`. (I am not sure)
- `demsg`
  - display the message sent by `printk`
  - it display RAM buffer content sent from kernel to our console.
- we can also view the message output by kernel in our log folder
  - `/var/log/`

# Virtual Filesystem.

- these filesystem do not store content on a disk drive we have.
- instead it's a virtual representation of kernel function mapped to be view as files.
- virtual filesytem store generated kernel output.
- example of virtual filesystem can be found in `/proc` and `/sysfs` folder

## Proc

- proc stands for process.
- it store process information generated by the kernel.
- most of the system application get information from kernel thru reading from `/proc`.
- we can view information of our system from reading the content of `proc` file
  - example `head /proc/meminfo` will give the kernel generate information about the usage of RAM in our system.
- we can perform tuning to our kernel by manipulating files in this filesystem.
- example is tuning our kernel network behaviour by editing value in `proc/sys/net` folder.
  - let say we want to enable ip-fowarding for our system.
  - we can edit value of `/proc/sys/net/ipv4/ip_forward` from 0 to 1.
  - `echo 1 > /proc/sys/net/ipv4/ip_forward`.
  - this will tune our kernel to enable ip_forward and we can now acts like a router.
- the weird looking folder named with numbers when we `ls /proc` is actually our currently running process.
  - the number is actually a process id (PID).
  - each running process are named with its PID.
  - we can view info of the running process by diving into these folder.
  - we can kill it by removing the folder.
  - our `ps` command takes it information from this folder.
  - to get the PID of specific command we can use `pidof <commandname>`
    - example we can get pid of our current shell using `pidof bash`
    - then we can go into the directory `cd /proc/3905`
    - here we can see multiple file associated with current running process.
    - we can see the `fd` folder that stands for file descriptor.
    - in this folder there is 3 or more number files start with 0, 1, 2
      - `0` stand for std input
      - `1` stand for std output
      - `2` stand for std error
    - whenever we create a new file descriptor for this process.
    - a new number will be spawn in the `fd` directory.

## Sysfs (sys filesystem)

- sysfs is located in `/sys`.
- it's use to store `kernel object` information.
- it's usually contains hardware information.

- Device (dev)

  - [Device File](https://wiki.archlinux.org/title/Device_file), is usually located in `dev` folder.
  - contains information about device files.
  - devices files is the interface to a actual hardware device.
  - it the representation of device hardware as file in our filesystem.
  - there are few type of device file in linux

    - character device
    - block device.
    - network device.

  - in `character device` we access information thru `stream of sequential data` one byte to another.
    - when making a character device driver, we can make use of `open()`,`read()`,`write()` and `ioctl()` function call to interact with the device.
    - we can use `open()` to open a file descriptor for a particular device.
    - we can use `read()` to read stream value sent by the device.
    - we can use `write()` to write into the device or write to some other file descriptor.
    - it is like in programming, where we want to write something to a file, we need to open a file descriptor using the `open()` function.
    - this open function either in `C++`, `python` is actually calling the system `open()` library to create a file descriptor.
  - `block device` is like our hdd,ssd, we can found it in `/sys/block` folder.
  - try run this : `sudo strace fdisk -l |& grep /dev/`
