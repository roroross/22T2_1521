# print the square of a number 
# $t0 = x, $t1 = y
main:
        la      $a0,    prompt
        li      $v0,    4
        syscall                 ## printf("Enter a number: ");

        li      $v0,    5       # scanf("%d", x);
        syscall 
        move    $t0,    $v0     # saving what was in v0 -> t0

        mul     $t1,    $t0,    $t0     # y = x * x;

        move    $a0,    $t1     # printf("%d\n", y);
        li      $v0,     1
        syscall 

        li      $a0, '\n'
        li      $v0, 11
        syscall 

        jr      $ra 

        .data
prompt:
        .asciiz "Enter a number" 



