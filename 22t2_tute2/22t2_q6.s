main:
    la      $a0,    prompt  # printf("Enter a number: ");
    li      $v0,    4
    syscall 

    li      $v0,    5       # scanf("%d", &x);
    syscall

    move    $t0,    $v0     # moving what i scanned from v0 to t0
    ble     $t0,    100,    small_big 
    bge     $t0,    1000,   small_big

    la      $a0,    medium_string
    li      $v0,    4
    syscall

    j       end

small_big:
    la      $a0,    small_big_string
    li      $v0,    4
    syscall

end:    
    jr  $ra             #return          

    .data
prompt: 
    .asciiz "Enter a number: "

small_big_string:
    .asciiz "small/big \n"

medium_string:
    .asciiz "medium \n"