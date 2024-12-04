.data
	print: .asciiz "\nThe Numbers are equal "
	print2: .asciiz "\nThe numbers are not equal"

.text

	main:
	     addi $t0, $zero, 1
	     addi $t1, $zero, 2
	     
	     sgt $s0, $t0, $t1
	     bne $s0, $zero, print
	     bge $s0, $zero, print2
	     
	     li $v0, 10
	     syscall