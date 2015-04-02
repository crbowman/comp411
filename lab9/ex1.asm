#
# Lab 9: More Recursion
#
	
.data 0x0	
	newLine: .asciiz "\n"
	
main:	
	li, $v0, 5		# Load read int syscall
	syscall			
	la $a0, $v0		# Store int in $a0
	beq $a0, $0, exit       # Exit if input is zero
	jal fib			# Call fib on input
	la $a0, $v0		# Load result in $a0
        li $v0, 4 		# Load print syscall
	syscall			# Print
	la $a0, newLine         # Load a newline in $a0
	syscall                 # Print
	j main

fib:	
	addi $sp, $sp, -8  	# Adjust stack pointer
	sw $ra, 0($sp)		# Save return address to stack
	sw $a0, 4($sp)          # Save n to stack
	sw $t1, 8($sp)		# \
	sw $t2, 12($sp)	        #  } Save 3 utility registers
	sw $t3, 16($sp)         # /
	bne $a0, $0, else1      # Branch !(n == 0)
	li $v0, 0               # Set return value to 0
        addi $sp, $sp, 8        # Reset stack pointer
	jr $ra		        # Return
	
else1:	
	li $t1, 1		# Set $t1 to 1
	bne $a0, $t1, else2     # Branch !(n == 1)
	li $v, 1              	# Set return value to 1
	addi $sp, $sp, 8	# Reset stack pointer
	jr $ra 			# Return
	
else2:	
	addi $a0, 4($sp), -1	# Set arg to n-1
	jal fib
	lw $t2, 0($v0)		# Set $t2 to fib(n-1)
	addi $a0, 4($sp), -2	# Set arg to n-2
	jal fib
	lw $t3, 0($v0) 		# Set $t3 to fib(n-2)
	add $v0, $t1, $t2	# Set return value to fib(n-1) + fib(n-2)
	lw $ra, 0($sp)		# Reset return address
	sw 8($sp), $t1		# \
	sw 12($sp), $t2		#  } Reset utility registers
	sw 16($sp), $t3		# /
	addi $sp, $sp, 8	# Reset stack pointer
	jr $ra			# Return

exit:	
	move $a0, $0		# Set arg to 0	
        j print			# Print arg
	li $v0, 10		# Load exit syscall
	syscall			# Exit
	

