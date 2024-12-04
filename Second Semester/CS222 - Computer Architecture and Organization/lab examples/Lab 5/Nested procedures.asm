.data
	space: .asciiz "\n"

.text

	main: 
		addi $s0, $zero, 10
		
		#Jump and link to increaseRegister
		jal increaseRegister
		
		#value
		li $v0, 4
		la $a0, space
		syscall
		
		
		jal printVal
		
	#end of program.
	li $v0, 10
	syscall
	
	
	increaseRegister:
		#allocate register divisible by -4; which is -8, -12 and so on. 
		#To make a space in the stack for the binary 
		addi $sp, $sp, -4
		#addi $sp, $sp, -8
		sw $s0, 0($sp)
		sw $ra, 4,($sp) 
		
		addi $s0, $s0, 30
		
		#Nested proceedure
		jal printVal
		
	
		#To restore the value back to the original number given, 
		#restore the old space in the stack.
		lw $s0, 0($sp)
		lw $ra , 4($sp)
		addi $sp, $sp, 4
		
		jr $ra
		
	printVal:
		#New Value
		li $v0, 1
		move $a0, $s0
		syscall
			
		jr $ra
