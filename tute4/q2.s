main:
						#t0 = row, #t1 = col 
	li 	$t0, 	0 			#$t0 = 0
row_loop:
						#if row >= 6, go to row_loop_end
	bge 	$t0, 	6,	row_loop_end	# for (int row = 0; row < 6; row++)
	
	li	$t1,	0			#$t1 = 0
col_loop:
						# if col >= 12, go to col loop end
	bge 	$t1, 	12, 	col_loop_end	# for (int col = 0; col < 12; col++)

						# 2d array #offset: array[i][j] = (i * N_COL) + j
	mul 	$t2, 	$t0, 	12		# t2 = i * N_COL
	add 	$t3, 	$t2,	$t1		# t3 = (i * C_COL) + j

	la 	$t4, 	flag 			# loading the address of the flag array
	add	$t5,	$t3,	$t4		# adding the offset to the address of the flag 

						#t5: is the address of flag[row][col]
						# ($t5) = flag[row][col]
	lb 	$a0, 	($t5)			# loading whatveer is in t5 into a0
	li 	$v0, 	11			# print char 
	syscall 

	# e.g. if we dont save our $ra on the stack, we would be in am
	#infinite loop from here to the end cose jr ra will jump to here! 
	jal 	function2
	#blah 

	addi	$t1, 	$t1, 	1		#col ++
	j 	col_loop
col_loop_end:
	li 	$a0, 	'\n' 			# printf \n
	li 	$v0, 	11
	syscall 


	addi 	$t0, 	$t0, 	1 		# row++
	j 	row_loop
row_loop_end:

	li 	$v0, 	0
	jr 	$ra 				# rturn 0 :)

############ stack frame example 
functio2:
	# 	blah
	jr 	$ra

.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

