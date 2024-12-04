.data
	Number1: .asciiz "Number 1: "
	Number2: .asciiz "\nNumber 2: "
	Number3: .asciiz "\nNumber 3: "
	Number4: .asciiz "\nNumber 4: "
	Number5: .asciiz "\nNumber 5: "
	Double1: .double 5.5
	Double2: .double 2.2
	
.text
	ldc1, $f10, Double1
	ldc1, $f16, Double2
	
	add.d $f4, $f10, $f16
	mul.d $f6, $f10, $f16
	div.d $f8, $f10, $f16
	sub.d $f14, $f10, $f16
	
	# Printing 1
	la $a0, Number1
	li $v0, 4
	syscall
	
	li $v0, 3
	mov.d $f12, $f4
	syscall
	
	# Printing 2
	la $a0, Number2
	li $v0, 4
	syscall
	
	li $v0, 3
	mov.d $f12, $f6
	syscall
	
	# Printing 3
	la $a0, Number3
	li $v0, 4
	syscall
	
	li $v0, 3
	mov.d $f12, $f8
	syscall
	
	# Printing 4
	la $a0, Number4
	li $v0, 4
	syscall
	
	li $v0, 3
	mov.d $f12, $f14
	syscall