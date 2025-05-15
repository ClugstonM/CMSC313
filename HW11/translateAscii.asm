;;;  translateAscii.asm
;;;  Michael Clugston
;;;  May 15, 2025
;;;  Translate bytes into corresponding ASCII values and print

	SECTION .data
inputBuf:
	db  0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A
spaceChar:
	db 0x20
newLine:
	db 0x0A
	
	outputSize equ 0x10
	inputSize equ 0x08

	
	SECTION .bss
outputBuf:
	resb 80

	
	SECTION .text
	global _start
_start:
	mov esi, 0
	mov edi, 0
L1:
	;; Isolate first digit of byte
	mov eax, [inputBuf + esi]
	and eax, 0x00F0
	shr eax, 4

	;; Check if digit is 0-9
	cmp eax, 0x0A
	jge Letter1 		; Jump to Letter1 if it is a letter (A-F)
	add eax, 0x30
	jmp Continue1

Letter1:
	add eax, 0x37
	
Continue1:
	;; Append corresponding ASCII value to outputBuf
	mov [outputBuf + edi], eax
	inc edi
	
	;; Isolate second digit of byte
	mov eax, [inputBuf + esi]
	and eax, 0x000F

	;; Check if digit is 0-9
	cmp eax, 0x0A
	jge Letter2 		; Jump to Letter2 if it is a letter (A-F)
	add eax, 0x30
	jmp Continue2

Letter2:
	add eax, 0x37

Continue2:
	;; Append corresponding ASCII value to outputbuf
	mov [outputBuf + edi], eax
	inc edi

	;; Loop until end of inputBuf
	inc esi
	cmp esi, inputSize
	jl L1

	
	;; Print outputBuf
	mov esi, outputBuf
	mov edi, 0
PrintLoop:
	;; Print one digit
	mov eax, 4
	mov ebx, 1
	mov edx, 1
	mov ecx, esi
	int 0x80
	inc esi
	inc edi

	;; Check parity of edi after incrementing
	mov eax, edi
	and eax, 0x0001
	cmp eax, 0x01
	je ContinuePrint
	;; Print space if edi is now even
	mov eax, 4
	mov ebx, 1
	mov ecx, spaceChar
	mov edx, 1
	int 0x80

ContinuePrint:
	;; Loop until end of outputBuf
	cmp edi, outputSize
	jl PrintLoop
	
	;;  print newLine
	mov eax, 4
	mov ebx, 1
	mov ecx, newLine
	mov edx, 1
	int 0x80

	;; Exit
	mov ebx, 0
	mov eax, 1
	int 0x80


	
