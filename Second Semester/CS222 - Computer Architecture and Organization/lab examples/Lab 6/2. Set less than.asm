.data
	m1: .asciiz "the number is less than the other: "
	m2: .asciiz "the number is greater than the other: "

.text
     
     main:
     	addi $t0, $zero, 1
     	addi $t1, $zero, 2
     	
     	sgt $s0, $t0, $t1
     	bne $s0, $zero, print
     	bge $s0, $zero, print2
     	
     	li $v0, 10
     	syscall
     	
     print:
     	li $v0, 4
     	la $a0, m1
     	syscall
     	
     	li $v0, 10
     	syscall
     	
      print2:
     	li $v0, 4
     	la $a0, m2
     	syscall
     	
     	li $v0, 10
     	syscall
     	
     
