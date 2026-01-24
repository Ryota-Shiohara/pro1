	addi x11, x0, 0
	jal x1, func1
	addi x12, x11, 0
	addi x4, x0, 0
	lw x5, x4, 0
	lw x6, x4, 0
	lw x7, x4, 0
	addi x8, x0, 4
	lw x9, x8, 0
	lw x10, x4, 0
	addi x14, x0, 20
	sw x5, x14, 0
	sw x6, x14, 4
	sw x7, x14, 8
	sw x9, x14, 12
	sw x10, x14, 16
	ecall x0, x0, x0
func1: addi x11, x0, 10
	addi x11, x11, 5
	addi x0, x0, 0
	jalr x0, x1, 0
