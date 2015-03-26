	#---------------------------------
# Lab 7: PPM to PGM converstion
#
#

.data 0x0
	magicNumber:	.asciiz	"P2\n"
	newLine:	.asciiz	"\n"

.text 0x3000

main:
	li $v0, 8  				#load read string syscall
	syscall                                 #read string: magic number
	move $t0, $v0	                       
	
	li $v0, 5				#load read integer syscall
	syscall					#read integer: rows
	move $t1, $v0				#load rows into $t0
	
	li $v0, 5				#load read integer syscall
	syscall					#read integer: columns
	move $t2, $v0 				#load columns into $t1
	
	li $v0, 5 				#load read integer syscall
	syscall					#read integer: ppm_max
	move $t3, $v0    		        #load ppm_max into $t3
	
	li $v0, 4
	la $a0, magicNumber
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall
	li $v0, 4
	la $a0, 4
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	li $v0, 4
	la $a0, 4
	syscall
	
	li $v0, 1
	li $a0, 255
	syscall	
	
	mult $t1, $t2
	mflo $t4
	
	addi $t9, $t4, 1
	li $t5, 0
	li $t6, 255
	li $t7, 3
	la $t8, ($t3)
loop:
	beq $t5, $t4, exit
	
	li $v0, 4	
	la $a0, 4
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	li $v0, 5
	syscall
	move $t2, $v0
	
	add $t0, $t0, $t1
	add $t0, $t0, $t2
	
	mult $t0, $t6
	mflo $t0
	
	mult $t8, $t7
	mflo $t1

	div $t0, $t1
	mflo $t3

	li $v0, 1
	move $a0, $t3
	syscall
	
	
	addi $t5, $t5, 1 
	j loop
	
exit:
	li $v0, 10				#System call code 10 for exit
	syscall					#exit the program
