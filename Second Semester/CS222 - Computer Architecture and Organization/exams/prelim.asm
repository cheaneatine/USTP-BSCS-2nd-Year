.data
	Number1: .asciiz "Number 1: "
	Number2: .asciiz "\nNumber 2: "
	Number3: .asciiz "\nNumber 3: "
	Number4: .asciiz "\nNumber 4: "
	Number5: .asciiz "\nNumber 5: "

.text
	addi $t0, $zero, 2
	
	# Addition
	add $t1, $t0, 30
	
	li $v0, 4
	la $a0, Number1
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall		# 32
	
	# Subtraction
	sub $t2, $t0, -14
	
	li $v0, 4
	la $a0, Number2
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall		# 16
	
	# Division
	div $t2, $t0
	
	mflo $s1
	
	li $v0, 4
	la $a0, Number3
	syscall
	
	li $v0, 1
	move $a0, $s1
	syscall		# 8
	
	# Multiplication
	mult $t0, $t0
	
	mflo $s2
	
	li $v0, 4
	la $a0, Number4
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	# Number 5
	
	li $v0, 4
	la $a0, Number5
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall