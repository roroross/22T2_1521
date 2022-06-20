main:
main_prol:
    begin			        # begin a new stack frame
	push	$ra		        # | $ra

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
	pop	    $ra		        # | $ra
	end			            # ends the current stack frame

	li	    $v0,    0
	jr	    $ra		        # return 0;


sum4:
sum4_pro: 
    begin			        # begin a new stack frame
	push	$ra		        # | $ra
    push    $s0             # c in s0
    push    $s1             # d in s1
    push    $s2             # e
    push    $s3             # f
                            # a0 = a, #a1 = b 
    move    $s0,    $a2     # c in s0
    move    $s1,    $a3     # d in s1

sum4_redo: 
    jal     sum2            #sum2 (a, b), a0 = a, a1 = b

    move    $s2,    $v0     # save s2 =  int e = sum2(a, b);

    move    $a0,    $s0
    move    $a1,    $s1     # a0 = c, a1 = a1

    jal     sum2            # sum2 (a,b)

    move    $s3,    $v0     # s3 = int f = sum2(c, d);
    
    move    $a0,    $s2     # a0 = e, a1 = f
    move    $a1,    $s3
    jal     sum2            # sum2(e, f);
    
sum4_epi: 
    pop     $s3
    pop     $s2
    pop     $s1
    pop     $s0
	pop	    $ra		        # | $ra
	end			            # ends the current stack frame

	jr	    $ra		

sum2:
    # sum doesnt call functions, so doesnt need to have a stack frame.
    add     $v0,    $a0,    $a1
    jr      $ra