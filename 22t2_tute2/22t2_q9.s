main:

    la  $a0,    msg1
    li  $v0,    4
    syscall             #printf "n = "

    li  $v0,    5   
    syscall             #scanning in our int

    move    $s0, $v0    # saving what we scanning to  a s register 

    # s0 = n, s1 = i, s2 = fac
    li      $s1,    1
    li      $s2,    1

loop:       
    bgt     $s1,    $s0,    end
    mul     $s2,    $s2,    $s1
    add     $s1,    $s1,    1    
    j       loop

end:
    la  $a0, mgsg2      # n! = 
    li  $v0,    4
    syscall 

    move    $a0,    $s2     #printing n!
    li      $v0, 1
    syscall

    la  $a0, mgsg3      # \n
    li  $v0,    4
    syscall 

    jr  $ra
    .data:
msg1:   .asciiz "n =  "
msg2:   .asciiz "n! = "
eol:    .asciiz     "\n"
















#######################################

main:

    la      $a0,    msg1        # printf("n  = ");
    li      $v0,    4
    syscall 

    li      $v0,    5           # scanf("%d", &n);
    syscall

    move    $s0,    $v0         # save scanned value into s0
                                # s0 = n

    li      $s1,    1           # s1 = i
    li      $s2,    1           # s2 = fac  

factorial:
    bgt     $s1,    $s0,    end         # if (i > n) goto end;
    mul     $s2,    $s2,    $s1          # fac = fac * i
    add     $s1,    $s1,    1           # i++

    j       factorial

end:
    la      $a0,    msg2            #  printf ("n! = ")
    li      $v0,    4
    syscall 

    move    $a0,    $s2             # move s2 into a0
    li      $v0,    1
    syscall                         # printf "%d"

    la      $a0,    eol            #  printf ("\n")
    li      $v0,    4
    syscall 

    jr      $ra                     #return

    .data   
msg1:   .asciiz     "n  = "
msg2:   .asciiz     "n! = "
eol:    .asciiz     "\n"