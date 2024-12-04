.data
	number1: .word 15        
	number2: .word 10
.text
	lw $t0, number1     #t0 = 15
	lw $t1, number2	    #t1 = 10
	
	sub $t2, $t0, $t1   #t2 = t0 - t1
	sub $t3, $t0, $t2   #t3 = t0 - t2
	
	li $v0, 1
	#add $a0, $zero, $t2
	move $a0, $t3
	
	
	syscall
	
