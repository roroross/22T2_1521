# print the square of a number. 
# this is a comment. 
#1521 mipsy q9_22t2.s 11    
main: 
    la  $a0,   prompt      # printf("Enter a number: ");
    li  $v0,    4
    syscall

    li  $v0,    5          # scanf("%d", x);
    syscall 
    move    $t0, $v0        #t0 = x
    # $v0 is what the scann returned, and now we copy v0 into t0

                            # t1 =y 
    mul     $t1, $t0, $t0   # t1 = t0 * t0 // y = x * x;

    move      $a0, $t1        # printf("%d", y); 
    #move copies whatever was in t1 into a0
    li      $v0, 1
    syscall 

    li      $a0, '\n'       # printf("%c", '\n');
    li      $v0, 11
    syscall 

    jr      $ra             #return     

    .data
prompt:
    .asciiz "Enter a Number: "