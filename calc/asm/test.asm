	addi x4,x0,0
	addi x5,x0,9
    addi x8,x0,2
	sll x5,x5,x8
	addi x8,x0,5
loop: lw x6,x4,0
	lw x7,x5,0
	sw x7,x4,0
	sw x6,x5,0
	addi x4,x4,4
	addi x5,x5,-4
	addi x8,x8,-1
	bne x8,x0,loop
	ecall x0,x0,x0
