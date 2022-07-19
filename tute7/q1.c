#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void) {
    //uint16_t sum = (30000u + 30000u);
    int16_t sumI = (30000 + 30000);
    printf("%d\n", sumI);
    return 0;
}

/*
integer overflow. ->> flowing past the max bound of ur integer space
30000
16 bits with signed int16_t: the max range for a signed int is -2^15 -> 2^15 -1 
= -32768 -> 32767

30000 + 30000 = 60000
keep adding till you get the range
60000-32768= 27232 from the LHS neg side which is acutally 32768 - 27232 = 5536 down the number line on the negative side

*/