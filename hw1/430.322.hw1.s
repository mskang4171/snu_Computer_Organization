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
	.ident	"GCC: (GNU) 9.2.1 20191120 (Red Hat 9.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
