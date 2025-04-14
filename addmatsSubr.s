	.file	"addmatsSubr.c"
	.text
	.globl	addMatracies
	.type	addMatracies, @function
addMatracies:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 3, -12
	movl	$0, -8(%ebp)
	jmp	.L2
.L3:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %ecx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	8(%ebp), %eax
	addl	%ebx, %eax
	addl	%ecx, %edx
	movl	%edx, (%eax)
	addl	$1, -8(%ebp)
.L2:
	cmpl	$4, -8(%ebp)
	jle	.L3
	nop
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	addMatracies, .-addMatracies
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$64, %esp
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	movl	$0, -28(%ebp)
	movl	$0, -24(%ebp)
	movl	$1, -40(%ebp)
	movl	$0, -60(%ebp)
	movl	$0, -56(%ebp)
	movl	$0, -52(%ebp)
	movl	$0, -48(%ebp)
	movl	$0, -44(%ebp)
	movl	$2, -60(%ebp)
	leal	-60(%ebp), %eax
	pushl	%eax
	leal	-40(%ebp), %eax
	pushl	%eax
	leal	-20(%ebp), %eax
	pushl	%eax
	call	addMatracies
	addl	$12, %esp
	movl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240801 (Red Hat 14.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
