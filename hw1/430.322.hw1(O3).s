	.file	"430.322.hw1.c"
	.option nopic
	.text
	.align	1
	.globl	your_sort
	.type	your_sort, @function
your_sort:
	bge	a1,a2,.L13
	addi	sp,sp,-48
	sd	s1,24(sp)
	sd	s2,16(sp)
	sd	s3,8(sp)
	sd	ra,40(sp)
	sd	s0,32(sp)
	mv	s2,a2
	mv	s3,a0
	addiw	s1,a2,1
.L9:
	slli	a2,a1,2
	add	a2,s3,a2
	lw	a7,0(a2)
	mv	t3,a2
	mv	a4,s1
	mv	t1,a1
.L3:
	addiw	t1,t1,1
	blt	s2,t1,.L4
	lw	a5,4(t3)
	bltu	a5,a7,.L5
.L4:
	addi	a5,a4,-1
	slli	a5,a5,2
	add	a5,s3,a5
	j	.L7
.L17:
	addi	a5,a5,-4
	bgeu	a7,a3,.L6
.L7:
	mv	s0,a4
	addiw	a4,a4,-1
	lw	a3,0(a5)
	mv	a6,a5
	ble	a1,a4,.L17
.L6:
	blt	t1,a4,.L18
	lw	a5,0(a2)
	sw	a3,0(a2)
	mv	a0,s3
	addiw	a2,s0,-2
	sw	a5,0(a6)
	call	your_sort
	ble	s2,s0,.L19
	mv	a1,s0
	j	.L9
.L18:
	lw	a5,4(t3)
	sw	a3,4(t3)
	sw	a5,0(a6)
.L5:
	addi	t3,t3,4
	j	.L3
.L19:
	ld	ra,40(sp)
	ld	s0,32(sp)
	ld	s1,24(sp)
	ld	s2,16(sp)
	ld	s3,8(sp)
	addi	sp,sp,48
	jr	ra
.L13:
	ret
	.size	your_sort, .-your_sort
	.align	1
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
	mv	a1,a0
	addi	a2,a0,252
.L21:
	mv	a5,a1
.L23:
	lw	a4,0(a5)
	lw	a3,4(a5)
	bleu	a4,a3,.L22
	sw	a3,0(a5)
	sw	a4,4(a5)
.L22:
	addi	a5,a5,4
	bne	a5,a2,.L23
	addi	a2,a5,-4
	bne	a2,a1,.L21
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
	addi	sp,sp,-48
	sd	s0,32(sp)
	sd	s1,24(sp)
	sd	s2,16(sp)
	sd	s3,8(sp)
	sd	s4,0(sp)
	sd	ra,40(sp)
	mv	s2,a0
	mv	s1,a1
	li	a3,0
	li	s0,0
	lui	s4,%hi(.LC0)
	li	s3,64
.L28:
	lw	a4,0(s2)
	lw	a5,0(s1)
	mv	a1,s0
	addi	a0,s4,%lo(.LC0)
	addiw	s0,s0,1
	beq	a4,a5,.L27
	call	printf
	li	a3,1
.L27:
	addi	s2,s2,4
	addi	s1,s1,4
	bne	s0,s3,.L28
	beqz	a3,.L32
	ld	ra,40(sp)
	ld	s0,32(sp)
	ld	s1,24(sp)
	ld	s2,16(sp)
	ld	s3,8(sp)
	ld	s4,0(sp)
	addi	sp,sp,48
	jr	ra
.L32:
	ld	s0,32(sp)
	ld	ra,40(sp)
	ld	s1,24(sp)
	ld	s2,16(sp)
	ld	s3,8(sp)
	ld	s4,0(sp)
	lui	a0,%hi(.LC1)
	addi	a0,a0,%lo(.LC1)
	addi	sp,sp,48
	tail	puts
	.size	check, .-check
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-544
	li	a2,256
	li	a1,0
	mv	a0,sp
	sd	ra,536(sp)
	sd	s0,528(sp)
	sd	s1,520(sp)
	sd	s2,512(sp)
	call	memset
	addi	s2,sp,256
	li	a2,256
	li	a1,0
	mv	a0,s2
	call	memset
	li	a0,0
	call	srand
	mv	s0,sp
	mv	s1,s2
.L34:
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
	bne	s2,s0,.L34
	mv	a0,sp
	call	bubble_sort
	mv	a0,s2
	li	a2,63
	li	a1,0
	call	your_sort
	mv	a0,sp
	mv	a1,s2
	call	check
	ld	ra,536(sp)
	ld	s0,528(sp)
	ld	s1,520(sp)
	ld	s2,512(sp)
	li	a0,0
	addi	sp,sp,544
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.1 20191120 (Red Hat 9.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
