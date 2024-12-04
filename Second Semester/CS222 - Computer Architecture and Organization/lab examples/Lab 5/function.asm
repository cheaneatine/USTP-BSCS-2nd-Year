.data
	myhi:	.asciiz "Hi everyone. \n I'm  "
        mylo:   .asciiz " years old"
.text
	main:    #caller 
		jal displaymyhi 	#jump to the link - displaymyhi
		
						
		addi $s0, $zero, 29    
		
		li $v0, 1
		add $a0, $zero, $s0
		syscall
		
		li $v0, 4
		la $a0, mylo
		syscall
		
		
		li $v0, 10	#tells the program to stop or exit program
		syscall		#let's try without the li v0, 10
		
		
	#callee 	
	displaymyhi:       #callee
		li $v0, 4
		la $a0, myhi
		syscall
		
		jr $ra		#jump back to the address main
	