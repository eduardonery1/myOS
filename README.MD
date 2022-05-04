# MyOS 

This is a Operating system being built with the help of osdev.org articles and this guy: 
https://www.youtube.com/watch?v=RTKj4jdo_2s&list=PLHh55M_Kq4OApWScZyPl5HhgsTJS9MZ6M

The system is designed for x86 architecture. 

## The components
### Bootloader
I'm using grub. I know. I'm a sinner.
Be sure your BIOS allows unsafe boot if you are going to try it in your real machine.

### Kernel
The bare bones structure of the project is found in the loader.s and kernel.cpp files.
The loader sets up the registers and stack pointer so that the cpp application can work.

We can't use libraries, only C built-in types and assembly.

To create a printf function we only gotta write characters using a pointer to video memory address:```0xb8000``` . Each even index is responsible by color, the odd ones are for the characters.

### Global Descriptor Table 
The CPU requires a GDT so that it knows where the memory segments are. Each memory segment can be allocated for different things such as implementing the heap and protected segments.

#### Memory Segments
Each memory segment is defined by a descriptor and has some information for the CPU to facilitate pointer traversal (for the cpu, not for us).

### Interrupt Descriptor Table
#### Interrupt Handlers
#### Drivers
##### Keyboard
##### Mouse
To be done.

## Install
```bash
sudo apt-get install virtualboxvm xorriso
make mykernel.iso
```
Create a VM in Virtual Box called 'NeryOS' or change the name in the Makefile.
```bash
make clean
make run
```
This should open a vm with the OS. Currently it only detects keyboard strokes and printts "KEYBOARD {hex}".
The Keyboard Driver is working and reading the data.








