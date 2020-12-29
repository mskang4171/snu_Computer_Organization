	.file	"430.322.hw1.c"
	.option nopic
	.text
	.align	1
	.globl	your_sort
	.type	your_sort, @function
your_sort:
	bge	a1,a2,.L11
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	sd	s1,8(sp)
	sd	s2,0(sp)
	mv	s1,a0
	mv	s2,a2
	addiw	a5,a2,1
	slli	t1,a1,2
	add	t1,a0,t1
	lw	a6,0(t1)
	mv	a2,t1
	mv	a7,a1
	j	.L3
.L4:
	slli	a4,a5,2
	add	a4,s1,a4
.L7:
	mv	s0,a5
	addiw	a5,a5,-1
	bgt	a1,a5,.L6
	addi	a4,a4,-4
	lw	a3,0(a4)
	bgtu	a3,a6,.L7
.L6:
	bge	a7,a5,.L8
	lw	a3,4(a2)
	slli	a4,a5,2
	add	a4,s1,a4
	lw	a0,0(a4)
	sw	a0,4(a2)
	sw	a3,0(a4)
.L5:
	addi	a2,a2,4
.L3:
	addiw	a7,a7,1
	blt	s2,a7,.L4
	lw	a4,4(a2)
	bltu	a4,a6,.L5
	j	.L4
.L8:
	lw	a4,0(t1)
	slli	a5,a5,2
	add	a5,s1,a5
	lw	a3,0(a5)
	sw	a3,0(t1)
	sw	a4,0(a5)
	addiw	a2,s0,-2
	mv	a0,s1
	call	your_sort
	mv	a2,s2
	mv	a1,s0
	mv	a0,s1
	call	your_sort
	ld	ra,24(sp)
	ld	s0,16(sp)
	ld	s1,8(sp)
	ld	s2,0(sp)
	addi	sp,sp,32
	jr	ra
.L11:
	ret
	.size	your_sort, .-your_sort
	.align	1
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
	addi	a2,a0,252
	li	a1,63
	j	.L15
.L16:
	addi	a5,a5,4
	beq	a5,a2,.L19
.L17:
	lw	a4,0(a5)
	lw	a3,4(a5)
	bleu	a4,a3,.L16
	sw	a3,0(a5)
	sw	a4,4(a5)
	j	.L16
.L19:
	addiw	a1,a1,-1
	addi	a2,a2,-4
	beqz	a1,.L14
.L15:
	sext.w	a4,a1
	mv	a5,a0
	bgtz	a4,.L17
	j	.L19
.L14:
	ret
	.size	bubble_sort, .-bubble_sort
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	"Error : Wrong at array random_num[%d]\n"
	.align	3
.LC1:
	.string	"Success!"
	.text
	.align	1
	.globl	check
	.type	check, @function
check:
	addi	sp,sp,-64
	sd	ra,56(sp)
	sd	s0,48(sp)
	sd	s1,40(sp)
	sd	s2,32(sp)
	sd	s3,24(sp)
	sd	s4,16(sp)
	sd	s5,8(sp)
	mv	s2,a0
	mv	s1,a1
	li	a3,0
	li	s0,0
	lui	s5,%hi(.LC0)
	li	s4,1
	li	s3,64
	j	.L25
.L30:
	mv	a1,s0
	addi	a0,s5,%lo(.LC0)
	call	printf
	mv	a3,s4
.L24:
	addiw	s0,s0,1
	addi	s2,s2,4
	addi	s1,s1,4
	beq	s0,s3,.L29
.L25:
	lw	a4,0(s2)
	lw	a5,0(s1)
	beq	a4,a5,.L24
	j	.L30
.L29:
	beqz	a3,.L31
.L23:
	ld	ra,56(sp)
	ld	s0,48(sp)
	ld	s1,40(sp)
	ld	s2,32(sp)
	ld	s3,24(sp)
	ld	s4,16(sp)
	ld	s5,8(sp)
	addi	sp,sp,64
	jr	ra
.L31:
	lui	a0,%hi(.LC1)
	addi	a0,a0,%lo(.LC1)
	call	puts
	j	.L23
	.size	check, .-check
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-544
	sd	ra,536(sp)
	sd	s0,528(sp)
	sd	s1,520(sp)
	sd	s2,512(sp)
	li	a2,256
	li	a1,0
	addi	a0,sp,256
	call	memset
	li	a2,256
	li	a1,0
	mv	a0,sp
	call	memset
	li	a0,0
	call	srand
	addi	s0,sp,256
	mv	s1,sp
	addi	s2,sp,512
.L33:
	call	rand
	sraiw	a5,a0,31
	srliw	a4,a5,25
	addw	a5,a4,a0
	andi	a5,a5,127
	subw	a5,a5,a4
	sw	a5,0(s0)
	sw	a5,0(s1)
	addi	s0,s0,4
	addi	s1,s1,4
	bne	s2,s0,.L33
	addi	a0,sp,256
	call	bubble_sort
	li	a2,63
	li	a1,0
	mv	a0,sp
	call	your_sort
	mv	a1,sp
	addi	a0,sp,256
	call	check
	li	a0,0
	ld	ra,536(sp)
	ld	s0,528(sp)
	ld	s1,520(sp)
	ld	s2,512(sp)
	addi	sp,sp,544
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.1 20191120 (Red Hat 9.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
