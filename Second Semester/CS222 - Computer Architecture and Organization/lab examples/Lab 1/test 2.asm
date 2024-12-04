.data 
	myHello: .asciiz "Hello World \n" 
	myChar:  .byte '2'
	mySpace: .asciiz "\n"
	age:     .word 29
	myfloat: .float 3.141516
	
	
.text
	li $v0, 4			#print function
	la $a0, myHello			#get memory from ram which is asciiz then load to $a0
	syscall				#execution of the program, or JUST DO IT!
	
	li $v0, 4  			#print function
	la $a0, myChar
	syscall
	
	li $v0, 4 			#print function
	la $a0, mySpace
	syscall
	
	li $v0, 1	
	lw $a0, age
	syscall
	
	li $v0, 4			#print function
	la $a0, mySpace
	syscall
	
	li $v0, 2
	lwc1 $f12, myfloat
	syscall
	
	li $v0, 4
	la $a0, mySpace
	syscall
	
	