.data
	Name: .asciiz "Vinnie"
	newline: .asciiz " \n"
	Age: .word 20
	School: .asciiz "\nUSTP"
	Remainder: .asciiz "\nRemainder: "
	Quotient: .asciiz "\nQuotient: "
	Addition: .asciiz "\nSum: "
	Subtraction: .asciiz "\nDifference: "
	Multiplication: .asciiz "\nProduct: "
	
.text
	addi $t0, $zero, 30
	addi $t1, $zero, 4
	addi $t2, $zero, 5
	
	# Name
	li $v0, 4
	la $a0, Name
	syscall
	
	# New Line
	li $v0, 4
	la $a0, newline
	syscall
	
	# Age
	li $v0, 1
	lw $a0, Age
	syscall
	
	# School
	li $v0, 4
	la $a0, School
	syscall
	
	# Division
	div $t0, $t1
	
	mflo $s0 # Quotient
	mfhi $s1 # Remainder
	
	# Remainder
	li $v0, 4
	la $a0, Remainder
	syscall
	
	li $v0, 1
	move $a0, $s1
	syscall
	
	# Quotient
	li $v0, 4
	la $a0, Quotient
	syscall
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	# Addition
	add $t3, $t1, $t1
	add $t4, $t3, $t1
	
	li $v0, 4
	la $a0, Addition
	syscall
	
	li $v0, 1
	move $a0, $t4
	syscall
	
	# Subtraction
	sub $t5, $t0, $t4
	
	li $v0, 4
	la $a0, Subtraction
	syscall
	
	li $v0, 1
	move $a0, $t5
	syscall
	
	# Multiplication
	mult $s1, $t5
	
	mflo $s2
	
	li $v0, 4
	la $a0, Multiplication
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall