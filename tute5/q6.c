#include <stdio.h>
#include <assert.h>

#define BIT_IN_INT 32   // assume an unsigned int is 32 bits 

typedef unsigned int Word;

// if BIT_IN_INT = 8

//  0000 0001    i = 0 word 
//  1000 0000    i = 7 new word 

// i = 0, --> pos = BIT_IN_INT - i - 1 = 8 - i - 1 = 7 

//  0000 0010    i = 1 word
//  0100 0000    i = 6 new word
// i = 1 --> pos = BIT_IN_INT - i - 1 = 8 - i - 1 = 8 - 1 - 1 = 6

// BIT_IN_INT - i - 1  --> gives us the reverse position in our word 

Word reverseBits(Word w) {
    Word new_word = 0; // 0000...00000000 in binary
    for (unsigned int i = 0; i < BIT_IN_INT; i++) {
        /*
        // check if the bit is set (= 1)
        // use AND, and set the reverse position in new_word to 1, if word = 1
        // other wise, if it is 0, we dont care. cose our new word is already 0 by default
        w = 0000 0001 0010 0011 0100 0101 0110 0111
            0000 0000 .........................0001 &        // i = 0
            -----------------------------------------
                                                  ^ 
                                                  1 = TRUE 
            then, we want 
        new word = 0000 0000 0000 0000 0000 0000 0000 000 0000 to be 
        new word = 1000 0000 0000 0000 0000 0000 0000 000 0000


        e.g. i = 1, shift 1 << 1 (shift 1 to the left by 1 bit)
        w = 0000 0001 0010 0011 0100 0101 0110 0111
            0000 0000 .....................000 0010 &        // i = 1
            -----------------------------------------
                                                 ^ 
                                                1 = TRUE 

             then, we want 
        new word = 1000 0000 0000 0000 0000 0000 0000 000 0000 to be 
        new word = 1100 0000 0000 0000 0000 0000 0000 000 0000

        through 
        new word = 1000 0000 0000 0000 0000 0000 0000 000 0000
                   0100 0000 .............................0000 |
                   __________________________________________
        new word = 1100 0000 0000 0000 0000 0000 0000 000 0000
        */
        //c = put a u after the 1 cose we are working with unsigned int. 
        if (w & (1u << i)){
            // we wanna pad the reverse bit. 
            // BIT_IN_INT - i - 1  --> gives us the reverse position in our word 
            new_word = new_word | (1u << (BIT_IN_INT - i - 1));
            //new_word |=  (1u << (BIT_IN_INT - 1 -i));
        }
    }
    return new_word;
}

int main(void) {
    //Word w = 0x1234567;

    //printf(reverseBits(w));
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
    return 0;
}