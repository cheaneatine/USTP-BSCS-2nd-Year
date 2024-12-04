.data
	#mul  has 3 registers, will be save to your desired register
	#mult  has 2 registers, since only two register available we can use hi and l0
	#sll is exponents x^e =  shift left logical
.text
	
	addi $s0, $zero, 10
	addi $s1, $zero, 4
	
	#mul $t0, $s0, $s1
	mult $s0, $s1
	#sll $s2, $s1, 4

	mflo $s2
	#mfhi $s2
	
	
	#add $s2, $t0, $zero
	#move $t2, $t0
	
	
	li $v0, 1
	move $a0, $s2
	syscall
	
