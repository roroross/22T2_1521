Q2.
Hex: 0x (base 16) e.g. 0x64 == 100
Octal: 0 or 0o (base8) e.g. 0144 == 100
Decimal: Starts with other number (base 10) e.g. 100
Binary: no standard notation in C (no 0b yet) 

Show what the following decimal values look like 
in 8-bit binary, 3-digit octal, and 2-digit hexadecimal:

a. 1
b. 8
c. 10
d. 15
e. 16
f. 100
g. 127
h. 200

ex.1 f
decimal = 100

binary:
e.g. 8 bits
b   0000 0000
2^  7654 3210

bin
    0000 0001 --> 2^0 = 1 (decimal)
    0000 1010 --> 2^1 + 2^ 3 = 2 + 8 = 9 (decimal)

decimal -> binary:
look at the greatest power of 2 that will fit in the number
100 = 2^6 + 36 
    = 2^6 + 2^5 + 4 
    = 2^6 + 2^5 + 2^2
      64    32      4

100 = 2^6 + 2^5 + 2^2 
bin:   01    1  00 1 00
no 2^4, 2^3, 2^1, 2^0 so 0 in their places 
thus, 0110 0100

binary -> octal: 
get binary notation, group into 3: 0 -> 7 (base 8)
when you have groups of 3, convert this number from 0 -> 7
01100100

001 100 100
1   4   4          | e.g. 100 -> 2^2 + 0*2^1 + 0*2^0

thus, octal: 144

Hexidecimals:
Decimal: 0 -> 9 10 11 12 13 14 15 
Hexs:    0 -> 9  A  B  C  D  E  F

generally hexs is very handy. the bottom (rightmost bit)bit is 2^0   

group binary into groups of 4

binary: 01100100 --> 0110 0100

0110 0100       0100 = 2^2 = 4, 0110 = 2^1 + 2^2 = 4 + 2 = 6
4+2   4
6     4
hex: 64

ex2. 10
decimal = 10

binary: 
- biggest power of 2 that fits into 10? 2^3
10 = 2^ 3 + 2 = 2^ 3 + 2^ 1

Binary:
00000000
    ^ ^
    '3''1'
00001010

Octal:
- group into 3s
00001010 -> 00 001 010
            0   1   2
Octal: 012

Hex:
what is 10 in Hexs?
Decimal: 0 -> 9 10 11 12 13 14 15 
Hexs:    0 -> 9  A  B  C  D  E  F

Hex: 0xA

Ex3 . g. 127

127 = 2^6 + 63
    = 2^6 + 2^5 + 31
    = 2^6 + 2^5 + 2^4 + 15
    = 2^6 + 2^5 + 2^4 + 2^3 + 7
    = 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 3
    = 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 1
    = 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0

127 = 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0
    0  1     1      1     1    1     1     1

binary: 01111111

octal:
split 
01 111 111
1  7    7

111 = 2^2+2^1+2^0 = 4+2+1 = 7

Octal: 177

Hexs: 
- split into 4
0111 1111
7     2^3 +2^2+2^1+2^0 = 8+4+2+1 = 15 = F

Hexs: 7F
ex4. h. 200
TRICK:
if we have binary, if you have double the number, just copy and shift everything to the left 
e.g. 100 = 2^6 + 2 ^ 5 + 2 ^ 2
*2
100 = 2^7 + 2^6 + 2^3

Binary:
100 = 0110 0100   << 1
200 = 1100 1000

octal: 
11 001 000
3   1   0

octal: 310

Hexs:
1100 1000
2^3+2^2  2^3
12     8
C      8

Hexs: C8

Binary -> decimal
inverse. add up the powers of 2s.

BITWISE OPERATIONS
LESSON:
symbol      name            what it does 
&           AND             if both bits are 1, it remains 1. Otherwise,0       e.g. a = 1, b = 0, a & b = 0
|           OR              if either of the bits are 1, it is 1. Otherwise, 0  e.g. a = 1, b = 0, a | b = 1
^           XOR             if only one of the bits is 1, it is 1, otherwise, 0 e.g. if you have two 1s, or two 0s that will turn into 0.
                            but if the two bits are different, it will turn into 1. good for togggling 
~           NOT             flip bit 
>>          RIGHT SHIFT     shifts everything down by given bits >>>> to the right - makes the number smaller 0011 >> 1 --> 0001
<<          LEFT SHIFT      shifts everything up (left) by by given bits - make the number bigger.   


3. 
uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;
What are the values of the following expressions:

a. a | b (bitwise OR)
b. a & b (bitwise AND)
c. a ^ b (bitwise XOR)
d. a & ~b (bitwise AND)
e. c << 6 (left shift)
f. a >> 4 (right shift)
g. a & (b << 1)
h. b | c
i. a & ~c
Give your answer in hexadecimal, 
but you might find it easier to convert to binary to work out the solution. 

S1. write uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001; in binary 

// a = 0101 0101 0101 0101
// b = 1010 1010 1010 1010
// c = 0000 0000 0000 0001

a. a | b == 0xFFFF
OR : if we have a 1 anywhere, we make it 1. if there is no 1, it is 0

a = 0101 0101 0101 0101
b = 1010 1010 1010 1010     |
------------------------
    1111 1111 1111 1111     Hex: 1111 -> 8+4+2+1 = 15 = F 
0 x  F    F    F     F
Hex: 0xFFFF

b. a & b == 0x0000
AND: if either of the bits are 0, then the result is 0

a = 0101 0101 0101 0101
b = 1010 1010 1010 1010     &
______________________________
    0000 0000 0000 0000
Hex: 0x0000

c. a^b 
XOR:  if one of them is 1 and one of them is 0, we have 1. a XOR b
1 OR 1 -> 1   
1 XOR 1 --> 0  0 XOR 0 --> 0

a = 0101 0101 0101 0101
b = 1010 1010 1010 1010     ^
______________________________
    1111 1111 1111 1111     Hex: 1111 -> 8+4+2+1 = 15 = F 
0 x  F    F    F     F
Hex: 0xFFFF

d. a & ~ b 
a & (~b)
a AND NOT b

b = 1010 1010 1010 1010
~b= 0101 0101 0101 0101   // flip all the bits 

so

a = 0101 0101 0101 0101
~b= 0101 0101 0101 0101     &
------------------------------
    0101 0101 0101 0101
Hexs: 5   5    5     5
Hex: 0x5555


e. c << 6
c left shift by 6. 
// c = 0000 0000 0000 0001  <<<<<<<< 6 bits
                  654 321
                  ^
// c = 0000 0000 0100 0000

Hexs: 0x0040

f. a >> 4
a = 0101 0101 0101 0101 >> right by 4 bits  >> 0000s

a = 0000 0101 0101 0101 //0101
                            ^ 
                            this is byebye
a = 0000 0101 0101 0101
Hexs: 0x0555

g. a & (b <<1) 
b = 1010 1010 1010 1010
b = 1 | 010 1010 1010 1010 0
      |_______________________|

b << 1 = 010 1010 1010 10100 << 1

b << 1 = 0101 0101 0101 0100

a       = 0101 0101 0101 0101
b << 1  = 0101 0101 0101 0100   &
______________________________
          0101 0101 0101 0100
                            ^ 
                            0&1 = 0
0x5554

h. b | c
// b = 1010 1010 1010 1010
// c = 0000 0000 0000 0001      |
------------------------------
       1010 1010 1010 1011
0x      A    A    A    B 

i. a & ~c == 0x5554
a = 0101 0101 0101 0101
c = 0000 0000 0000 0001
~c= 1111 1111 1111 1110

a = 0101 0101 0101 0101
~c= 1111 1111 1111 1110      &
______________________________
    0101 0101 0101 0100

0X5554
