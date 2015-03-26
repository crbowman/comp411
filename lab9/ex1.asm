fib:	addi $sp, $sp, -8  	# Adjust stack pointer
	sw $ra, 0($sp)		# Save return address to stack
	sw $a0, 4($sp)          # Save n to stack
	bne $a0, $zero, else1   # Branch !(n == 0)
	li $v, 0                # Set return value to 0
        addi $sp, $sp, 8        # Reset stack pointer
	jr $ra		        # Return
	
else1:	li $t1, 1		# Set $t1 to 1
	bne $a0, $t1, else2     # Branch !(n == 1)
	li $v, 1              	# Set return value to 1
	addi $sp, $sp, 8	# Reset stack pointer
	jr $ra 			# Return
	
else2:	addi $a0, 4($sp), -1	# Set arg to n-1
	jal fib
	lw $t2, 0($v0)		# Set $t2 to fib(n-1)
	addi $a0, 4($sp), -2	# Set arg to n-2
	jal fib
	lw $t3, 0($v0) 		# Set $t3 to fib(n-2)
	add $v0, $t1, $t2	# Set return value to fib(n-1) + fib(n-2)
	lw $ra, 0($sp)		# Reset return address
	addi $sp, $sp, 8	# Reset stack pointer
	jr $ra			# Return
	
	
