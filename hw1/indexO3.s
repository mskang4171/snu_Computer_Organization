	.file	"index.c"
	.text
	.p2align 4
	.globl	your_sort
	.type	your_sort, @function
your_sort:
.LFB0:
	.cfi_startproc
	endbr64
	cmpl	%edx, %esi
	jge	.L13
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	%esi, %r8d
	movl	%edx, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	leal	1(%rdx), %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
.L9:
	movslq	%r8d, %rax
	leal	1(%r8), %r9d
	leaq	(%r12,%rax,4), %r11
	movslq	%r9d, %r9
	movl	%ebx, %eax
	movl	(%r11), %edi
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%r9d, %r10d
	cmpl	%r9d, %r13d
	jl	.L4
	cmpl	%edi, (%r12,%r9,4)
	jb	.L5
.L4:
	movslq	%eax, %rdx
	leaq	-4(%r12,%rdx,4), %rdx
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L17:
	subq	$4, %rdx
	cmpl	%ecx, %edi
	jnb	.L6
.L7:
	movl	%eax, %ebp
	subl	$1, %eax
	movl	(%rdx), %ecx
	movq	%rdx, %rsi
	cmpl	%eax, %r8d
	jle	.L17
.L6:
	cmpl	%eax, %r10d
	jl	.L18
	movl	(%r11), %eax
	movl	%ecx, (%r11)
	leal	-2(%rbp), %edx
	movq	%r12, %rdi
	movl	%eax, (%rsi)
	movl	%r8d, %esi
	call	your_sort
	cmpl	%ebp, %r13d
	jle	.L19
	movl	%ebp, %r8d
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L18:
	movl	(%r12,%r9,4), %edx
	movl	%ecx, (%r12,%r9,4)
	movl	%edx, (%rsi)
.L5:
	addq	$1, %r9
	jmp	.L3
.L19:
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
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
