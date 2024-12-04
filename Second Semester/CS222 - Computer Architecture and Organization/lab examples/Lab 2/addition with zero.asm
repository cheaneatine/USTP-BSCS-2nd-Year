.data				#data is your variables that are stored in the memory
	number1: .word 15
	number2: .word 15

.text				#text is your instructions to the program.
	lw $t0, number1($zero)	#load to word from data (number1) to $t0
	lw $t1, number2($zero)  #load to word from data (number2) to $t1
	
	add $t2, $t0, $t1     #t2 = t0 + t1
	add $t3, $t2, -10	#t3 = t2 + (-10)
	add $t3, $t2, 100	#t3 = t2 + 100
	add $t4, $t3, $t2
	add $t5, $t3, $t4
	

	
	li $v0, 1
	#add $a0, $zero, $t2
	move $a0, $t5
	syscall
	
