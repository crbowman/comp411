	#---------------------------------
# Lab 5: Pixel Conversion
#
# Name: <YOUR-NAME-HERE>
# Onyen: <YOUR-ONYEN-HERE>
#
# --------------------------------
# Below is the expected output.
# 
# Converting pixels to grayscale:
# 0
# 1
# 2
# 34
# 5
# 67
# 89
# Finished.
# -- program is finished running --
#---------------------------------

.data 0x0
	startString:	.asciiz	"Converting pixels to grayscale:\n"
	finishString:	.asciiz	"Finished."
	newline:	.asciiz	"\n"
	pixels:		.word 	0x00010000,	0x010101,	0x6,		0x3333, 
				0x030c,		0x700853,	0x294999,	-1

.text 0x3000

main:
	ori $v0, $0, 4				#System call code 4 for printing a string
	ori $a0, $0, 0x0   	 		#address of startString is in $a0
	syscall					#print the string


#------- INSERT YOUR CODE HERE -------
	la $t0, pixels
loop:
	lw $t6, 0($t0)
	beq $t6, -1, exit
	lbu $t1, 0($t0)                        	# load red value into $t1
	lbu $t2, 1($t0)				# load green value into $t2
	lbu $t3, 2($t0)				# load blue value into $t3
	addu $t4, $t1, $t2                       # add red and green values
	addu $t4, $t4, $t3	                # add blue to sum of red and green
	addi $a0, $0, 3				# load 3 into $a0
	div $t4, $a0				# divide sum of rgb by 3
	mflo $t4 				# put quotient in $t4	
	ori $v0, $0, 1
	add $a0, $0, $0
	or $a0, $0, $t4
	syscall
	ori $v0, $0, 4
	la $a0, newline
	syscall
	addi $t0, $t0, 4
	j loop
	



#------------ END CODE ---------------


exit:

	ori $v0, $0, 4				#System call code 4 for printing a string
	ori $a0, $0, 33  			#address of finishString is in $a0; we computed this
						#  simply by counting the number of chars in startString,
						#  including the \n and the terminating \0

	syscall					#print the string

	ori $v0, $0, 10				#System call code 10 for exit
	syscall					#exit the program
