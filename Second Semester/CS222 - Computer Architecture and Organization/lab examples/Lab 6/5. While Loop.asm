.data
	message: .asciiz "Done!!!"
	n1: .asciiz ", "
.text
     main:
     
     	#addi $t0, $zero, 0
     	li $t0, 0
     	while: 
     		
     		bgt $t0, 10, exit
     		jal printnum
     		addi $t0, $t0, 1
     		
     		j while
     		
     	exit:
     		li $v0, 4
     		la $a0, message
     		syscall
     		
     	   	li $v0, 10
     	   	syscall
     	   	
     	
     	printnum:
     		li $v0, 1
     		add $a0, $t0, $zero
     		syscall
     		
     		li $v0, 4
     		la $a0, n1
     		syscall
     		
     		jr $ra
     		
