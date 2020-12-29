	.file	"index.c"
	.text
	.globl	your_sort
	.type	your_sort, @function
your_sort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movl	%edx, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbx
.L9:
	cmpl	%esi, %ebp
	jle	.L1
	movslq	%esi, %rax
	leal	1(%rbp), %edx
	leaq	(%rbx,%rax,4), %rdi
	leal	1(%rsi), %eax
	movl	(%rdi), %r10d
	cltq
.L3:
	movl	%eax, %r11d
	cmpl	%ebp, %eax
	jg	.L4
	cmpl	%r10d, (%rbx,%rax,4)
	jnb	.L4
.L5:
	incq	%rax
	jmp	.L3
.L4:
	movslq	%edx, %rcx
	leaq	-4(%rbx,%rcx,4), %rcx
.L7:
	movl	%edx, %r12d
	decl	%edx
	movl	(%rcx), %r8d
	movq	%rcx, %r9
	cmpl	%edx, %esi
	jg	.L6
	subq	$4, %rcx
	cmpl	%r8d, %r10d
	jb	.L7
.L6:
	cmpl	%edx, %r11d
	jge	.L8
	movl	(%rbx,%rax,4), %ecx
	movl	%r8d, (%rbx,%rax,4)
	movl	%ecx, (%r9)
	jmp	.L5
.L8:
	movl	(%rdi), %eax
	movl	%r8d, (%rdi)
	leal	-2(%r12), %edx
	movq	%rbx, %rdi
	movl	%eax, (%r9)
	call	your_sort
	movl	%r12d, %esi
	jmp	.L9
.L1:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	your_sort, .-your_sort
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
