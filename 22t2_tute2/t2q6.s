#thurs tute
main:
    la      $a0,    prompt      #printing 
    li      $v0,    4
    syscall

    li      $v0,    5       #scanning 
    syscall

    move    $t0,   $v0          #t0 = x
    # savoing the returned scanned vqalue into t0
    
    # if (x <=  100) goto small_big;
    ble     $t0,    100,    small_big 

    #if (x >= 1000) goto small_big;
    bge     $t0,    1000,   small_big
    la      $a0,    medium
    li      $v0,    4
    
    syscall
    j       end

small_big:
    la      $a0,    small_big
    li      $v0,    4
    syscall 
end:    
    jr      $ra         #return 



.data:
prompt: 
    .asciiz: "Enter a num: "
medium:
    .asciiz: "medium \n"
small_big:
    .asciiz "small/big \n"