.data
	#How to Use Jump and Link 
	#Jump Register Unconditionally...

.text
	main:		
		#Intialized the numbers
		addi $a1, $zero, 50
		addi $a2, $zero, 100
		
		#jump and link to the name indicated
		jal addnumbers
	
		li $v0, 1
		addi $a0, $v1, 0
		syscall 
		
		#executes or stops the program.
		li $v0, 10
		syscall
		
	#name link	
	addnumbers:
		add $v1, $a1, $a2
		#jump register back to the original caller.
		jr $ra
