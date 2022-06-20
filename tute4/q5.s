main:
main_prol:
    	begin			# begin a new stack frame
	push	$ra		# | $ra

main_body:
	li      $a0,    11      # sum4(11, 13, 17, 19);
	li      $a1,    13
	li      $a2,    17
	li      $a3,    19
	jal     sum4

	move    $a0,    $v0      # a0 is sum4(11, 13, 17, 19);
	li      $v0,    1
	syscall 

	li      $a0,    '\n'
	li      $v0,    11
	syscall 

main_epilogue:
	pop	    	$ra	# | $ra
	end			# ends the current stack frame

	li	$v0, 	0
	jr	$ra		# return 0;


sum4:
sum4_pro: 
    	begin			# begin a new stack frame
	push	$ra		# | $ra
	push    $s0     	# c in s0
	push    $s1     	
	push    $s2     	
	push    $s3     	
				# a0 = a, #a1 = b 

sum4_body:
	jal     sum2    #sum2(a,b)      
	move    $s0,    $v0     # s0 = e

	move    $s1,    $a2     #c
	move    $s2,    $a3     #d

	move    $a0,    $s1     # now a0 = c
	move    $a1,    $s2     # now a1 = d

	jal     sum2            # int f = sum2(c, d);
	
				#  return sum2(e, f);
	#move    $a0,    $v0    # save the returned value into a0, v0 = f
	move    $s3,    $v0     # s3 = f

	move    $a0,    $s3
	move    $a1,    $s0     
	jal     sum2

sum4_epi: 
	pop     $s3
	pop     $s2
	pop     $s1
	pop     $s0
	pop	$ra		# | $ra
	end			# ends the current stack frame

	#li	$v0, 0  	# !! this was the line that screwed us up. we returned 0 as opposed to the sum
	jr	$ra		# return 

sum2:
	# sum doesnt call functions, so doesnt need to have a stack frame.
	add     $v0,    $a0,    $a1
	jr      $ra