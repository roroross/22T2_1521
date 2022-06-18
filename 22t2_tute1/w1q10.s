# print the square of a number
main:                  # x,y in $t0, $t1
    la   $a0, prompt   # printf("Enter a number: ");  -> load address of prompt into $a0 so we can print it
    li   $v0, 4        # load number 4 into $v0 to indicate print string
    syscall

    li   $v0, 5         # scanf("%d", x); --> load number 5 into $v0 to indicate read int syscall
    syscall
    move $t0, $v0

    mul  $s1, $t0, $t0  # y = x * x --> multiply value of t0 *t0 to store in t1

    // function call

    // T0

    move $a0, $s1        # printf("%d", y); --> load t1 into a0
    li   $v0, 1          # print
    syscall

    li   $a0, '\n'      # printf("%c", '\n'); --> new line 
    li   $v0, 11        # copy number 11 into v0 to indicate print char syscall
    syscall

    jr   $ra            # return

    .data
prompt:
    .asciiz "Enter a number: "