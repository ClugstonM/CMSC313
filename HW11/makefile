translateAscii: translateAscii.o translateAscii.asm
	ld -m elf_i386 -o translateAscii translateAscii.o

translateAscii.o: translateAscii.asm
	nasm -f elf32 -g -F dwarf -o translateAscii.o translateAscii.asm
