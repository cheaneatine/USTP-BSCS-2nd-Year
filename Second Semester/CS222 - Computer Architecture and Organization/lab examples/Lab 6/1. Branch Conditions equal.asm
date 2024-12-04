.data
	m1: .asciiz "\nThe Numbers are equal "
	m2: .asciiz "\nThe numbers are not equal"

.text

	main:
	     addi $t0, $zero, 2
	     addi $t1, $zero, 2
	     
	     
	     #branch equal, if both value is equal then proceed to function indicated
	     beq $t0, $t1, Equal
	     #branch not equal, if both value is not equal then proceed to function indicated	     
	     bne $t0, $t1, NotEqual
	   	
	   	
	   	
	     li $v0, 10
	     syscall
	
	Equal:
	
		li $v0, 4
		la $a0, m1
		syscall
	
		li $v0, 10
	    	syscall
	
	
	NotEqual:
	
	 	li $v0, 4
		la $a0, m2
		syscall
		
		li $v0, 10
	    	syscall
	

	
