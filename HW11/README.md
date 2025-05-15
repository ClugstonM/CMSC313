Michael Clugston  
UMBC  
CMSC313@1430 mon/wed  
HW#11

# Overview
This program takes bytes of data from 'inputBuf' and converts them into the corresponding ASCII representation of those hex digits, which are then placed into 'outputBuf'. These values are then printed two at a time (e.g., 8A 6D 32).

This program uses 32-bit x86 nasm assembly.

# Files
- translateAscii.asm: Source assembly code
- makefile: Commands to compile program


# Building 
With the makefile:
- 'make translateAscii' will create the executable translateAscii
- 'make translateAscii.o' will create only the translateAscii.o dependency

Manually:
- 'nasm -f elf32 -g -F dwarf -o translateAscii.o translateAscii.asm' will create translateAscii.o from translateAscii.asm
- 'ld -m elf_i386 -o translateAscii translateAscii.o' will create the executable translateAscii from translateAscii.o
