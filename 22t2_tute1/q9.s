main: 
        #code for main fn
        # $s0 = n, $s1 = i, $s2 = fac 

        la      $a0,    message1
        li      $v0,    4
        syscall                 #printf("n  = ");

        li      $v0,    5
        syscall                 #scanf("%d", &n);

        # $s0 = n, n = return scan value
        move    $s0,    $v0

        li      $s1,    1       # fac = 1, $s1 = fac
        li      $s2,    1       # i = 1, $s2 = i

# keep it looping!! give a label name 
for_loop:
        bgt     $s2,    $s0,    outside_for_loop  # i > n, go to outside of for loop
        #i <= n .... we continue below. 
        ## for loop executed below
        mul     $s1,    $s1,    $s2     #fac *= i; fac = fac * i
        addi	$s2,    $s2,    1       # i++ -->  i = i+1

        j       for_loop                # keep looping

outside_for_loop:
        ## outside the for loop 
        la      $a0,   message2
        li      $v0,    4
        syscall                         #printf ("n! = ) -- print the string"n! = "

        move    $a0,    $s1             # moving $s1 into $a0
        li      $v0,    1
        syscall                         #printf("%d", fac) -- print int

        la      $a0,    '\n'
        li      $v0,    11
        syscall                         # printf("\n") -- new line

        jr      $ra                     # return 0

        .data:
message1:       .asciiz "n  = "
message2:       .asciiz "n! = "