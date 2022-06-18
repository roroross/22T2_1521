Q2. 

$0 = $zero 
- zero register 
- read only
- always has the value zero 
- values written to this register are discarded
 - it frequesntly is used as  a source register when we wanna copy constant values into another register or vice versa 


$1 = $at 
- assembler temporary register, used for various purposes
- e.g. one use is to hold the result of tests from branch pseudo instrauctions
- ENCOURAGES for programers to NOT use

$2 =  $v0 
- holds the return value of a function 

$4 = $a0
- a0 holds the 1st argument to a function
- we also have a0, a1,a2,a3.... so thats 4 arguments we can hold
- it holds it if the arg can fit in a 32 bit register
- if we have more have 32 bits, or more than 4 args, we can put it on the stack
 int lala(int  x, int y, int z)
 x - a0, y = a1, z = a2

$8 = $t0
- temporary register - used for holding temporary values when calculating instructions 
- thres 10 of these.. $t0...$t9 
- DONT RELY ON THESE VALUES TO PERSIST AND HOLD THE SAME VALUE OVER A FUNCTION call
((3+4)*11)*42 

$16 = $s0 
- 8 of these.. $s0.. $s7
- safe register 
- e.g. if u sVE A VALUE INTO THESE REGISTERS AND CALL A FUNCTION, THE SAME VALUE WOULD BE IN THIS REGITER AFTER THE FUNCTOIN RETURNS!!!!!

$26 = $k0
- also have $k1
- reserved for the OS< WE DONT TOUCH THIS EVER

$29 = $sp 
- stack pointer register 
- register holds the address of the top of the programs run time stack
- intial value is 0x7FFFFEFC, and it cahnges as it move down 
- each time a funciton is called, it will need to reduce $sp but an amount large enough to hold all of its non register local valriables, and for space for saving register vales

$31 = $ra 
- return address
- when a linking instruction is called e.g. jal, the address of the next instruction is stored in the register $ra. 
- links aer ofen used to implement function calls, e.g. 
when you wanna return, jr $ra, to return to the correct loaction