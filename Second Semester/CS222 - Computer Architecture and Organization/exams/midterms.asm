.data
	prompt_x: .asciiz "Enter your 1st value: "
	prompt_y: .asciiz "Enter your 2nd value: "
	sum: .asciiz "Sum of input value: "
	difference: .asciiz "Difference of New value input value: "
	multiplication: .asciiz "Multiplication of new value x input value: "
	division: .asciiz "Division of New value / New value: "
	preview_x: .asciiz "Preview Input Value: "
	preview_y: .asciiz "Preview Input Value: "
	newline: .asciiz " \n"

.text
	main:
    	# Prompt user for input x
   	la $a0, prompt_x
    	li $v0, 4
    	syscall

    	# Read integer input x
    	li $v0, 5
    	syscall
    	move $s0, $v0
    	
    	# Prompt user for input y
    	la $a0, prompt_y
    	li $v0, 4
    	syscall

    	# Read integer input y
    	li $v0, 5
    	syscall
    	move $s1, $v0
    	
    	# save registers
    	addi $sp, $sp, -8
    	sw $s0, 0($sp)
    	sw $s1, 4($sp)



    	# Calculate sum
    	add $s0, $s0, $s1
    	move $a0, $s0
    
    	li $v0, 4
    	la $a0, sum
    	syscall
    
    	li $v0, 1
    	move $a0, $s0
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall
    	
    	
    	
    	# Calculate difference
    	sub $s1, $s0, $s1
    	move $t0, $s1
    
    	li $v0, 4
    	la $a0, difference
    	syscall
    
    	li $v0, 1
    	move $a0, $s1
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall
    	
    	
    	
    	# Calculate multiplication
    	mul $s0, $s0, $s1
    	move $t0, $s0
    
    	li $v0, 4
    	la $a0, multiplication
    	syscall
    	
    	li $v0, 1
    	move $a0, $t0
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall
    	
    	
    	
    	# Calculate division
    	div $s0, $s1, $s0
    	mflo $t0
    
    	li $v0, 4
    	la $a0, division
    	syscall
    
    	li $v0, 1
    	move $a0, $t0
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall
    	
    	
    	
    	# Retrieve input values from stack
    	lw $s0, 0($sp)
    	lw $s1, 4($sp)
    	addi $sp, $sp, 8

    	# Print preview input values
    	la $a0, preview_x
    	li $v0, 4
    	syscall
    
    	li $v0, 1
    	move $a0, $s0
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall

    	la $a0, preview_y
    	li $v0, 4
    	syscall
   
    	li $v0, 1
    	move $a0, $s1
    	syscall
    	
    	li $v0, 4
    	la $a0, newline
    	syscall

    	# Terminate program
    	li $v0, 10
    	syscall
