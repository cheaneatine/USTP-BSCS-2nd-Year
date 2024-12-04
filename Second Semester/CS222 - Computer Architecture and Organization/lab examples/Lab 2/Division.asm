.data
	myspace: .ascii "\n"   
	Quote:  .asciiz "\nRemainder ="
	Remain:  .asciiz "\nQuotient ="


.text
	addi $t0, $zero, 30
	addi  $t1, $zero, 8
	
	
	#div $s0, $t0, $t1
	#div $s0, $t0, 10
	div $t0, $t1
	
	mflo $s0  #Quotient
	mfhi $s1  #Remainder
		
	li $v0, 4
	la $a0, Quote	
	syscall
		
	li $v0, 1
	move $a0, $s1
	#add $a0, $zero, $s1
	syscall
	
	#li $v0, 4
	#la $a0, myspace
	#syscall
	
	li $v0, 4
	la $a0, Remain	
	syscall
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	
	
