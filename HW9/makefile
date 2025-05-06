helloworld: helloworld.o helloworld.asm
	ld -m elf_i386 -o helloworld helloworld.o

helloworld.o: helloworld.asm
	nasm -f elf32 -g -F dwarf -o helloworld.o helloworld.asm
