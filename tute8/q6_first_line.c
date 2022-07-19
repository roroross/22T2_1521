#include <stdio.h>
#include <stdlib.h>
/*
which is given one command-line argument, the name of a file,
 and which prints the first line of that file to stdout. 
 If given an incorrect number of arguments, or if there was an error opening the file, it should print a suitable error message.

./q6_first_line q6_first_line.c
#include <stdio.h>
*/
int main(int argc, char *argv[]) {
    // we're only expecting one command line arg.
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    // fopen returns a file pointer used to access file, we use R!!
    // what should we use if we wanna do write? W
    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        // couldn't open the file, print an error message
        // to standard error
        fprintf(stderr, "%s: ", argv[0]);
        perror(argv[1]); // use perror to print the error message, tells us what went wrong
        return 1;
    }
    int c; // man fgetc
    // takes the file stream, and return eof when it reaches end or error. reutrns an int not a char.
    // needs to be able to return a char from 0..255, also  eof which is -1, which isnt included in the - o 255 range
    // so we need an in to put it in. 
    while ((c = fgetc(stream)) != EOF) {
        fputc(c, stdout); // put it to stdout
        if (c == '\n') { // stop when we read  new line. 
            break;
        }
    }
    // close the file, as the program is about to exit
    // this isn't necessary but is good practice
    fclose(stream);
    return 0;
}