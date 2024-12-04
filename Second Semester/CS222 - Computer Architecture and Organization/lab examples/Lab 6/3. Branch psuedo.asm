.data
	m1: .asciiz "The program runs "
	m2: .asciiz "The program still runs "
	
.text
     
     main:
     	addi $s0, $zero, -2
     	addi $s1, $zero, 2
     	
     	#bgt $s0, $s1, display
     	#blt $s0, $s1, display2
     	#b display2
     	#if 1 register
     	#bgtz $s0, display2
     	#bltz $s0, display
     	
     	li $v0, 10
     	syscall
 
     
     display:
     	li $v0, 4
     	la $a0, m1
     	syscall
     	  
     	 li $v0, 10
     	syscall
     	 
     display2:
     	li $v0, 4
     	la $a0, m2
     	syscall
     	
     	li $v0, 10
     	syscall
     	
