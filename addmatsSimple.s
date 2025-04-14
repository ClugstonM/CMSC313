	.file	"addmatsSimple.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$64, %esp
	movl	$0, -44(%ebp)
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	movl	$0, -28(%ebp)
	movl	$1, -44(%ebp)
	movl	$0, -64(%ebp)
	movl	$0, -60(%ebp)
	movl	$0, -56(%ebp)
	movl	$0, -52(%ebp)
	movl	$0, -48(%ebp)
	movl	$2, -64(%ebp)
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	movl	-44(%ebp,%eax,4), %edx
	movl	-4(%ebp), %eax
	movl	-64(%ebp,%eax,4), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%edx, -24(%ebp,%eax,4)
	addl	$1, -4(%ebp)
.L2:
	cmpl	$4, -4(%ebp)
	jle	.L3
	movl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240801 (Red Hat 14.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
