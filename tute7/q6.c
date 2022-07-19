// Write a C function, six_middle_bits, which, given a uint32_t, extracts and returns the middle six bits.

#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t number) {
    /*
    Logic: 
        want to extract 6 bits in the middle
        want to have a mask that can 6 middle bits. -
        e.g. a mask that covers 6 bits 0011 1111
        converting 0011 1111 -> 0x3F

        e.g. number =  0000 0000 0000 0111 1110 0000 0000 0000   // a 32 bit integer
                                       ^^^ ^^^
                      0 0000 0000 0000 0000 0000 0000 0111 111   
        // now the 6 middle bits are at the very end 

        what do we do to EXTRACT the bits? 
        --> we comparing (using AND) with our mask: 0011 1111 -> 0x3F to get the 6 bits
        --> we use AND &, so if both was 1, we get 1, if it was 0, 0 & 1 = 0

        so we can extract the exact  last 6 digits of the integer. 
        because whatever is 0, still is 0, and whatever is 1, will be 1 in our return                
    */

   /*
   uint32_t result = number >> 13;  // shift by 13 to get the middle 6 bits to the end
   result = result & 0x3F;          // mask wth 0x3F which is 0011 1111
   return result;                   // return our result which has the middle 6 bits
    */
   // even quicker: 
   return (number >> 13) & 0x3F; 
}