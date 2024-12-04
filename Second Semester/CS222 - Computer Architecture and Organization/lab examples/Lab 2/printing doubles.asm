.data
	myDB: .double 7.2231	
	zeroDB: .double 3.1

.text
	ldc1 $f2, myDB		#load double from Coprocessor1 then store it to $f2 and $f3
	ldc1 $f0, zeroDB	#load double from Coprocessor1 then store it to $f0 and $f1
	
	li $v0, 3		#print double
	add.d $f12, $f2, $f0	#operation to print double because in double there is no $zero
	syscall 


