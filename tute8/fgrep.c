/*
Write a C program, fgrep.c, which is given 1+ command-line arguments which is a string to search for.
If there is only 1 command-line argument it should read lines from stdin and print them to stdout iff they contain the string specified as the first command line argumenbt.

If there are 2 or more command line arguments, it should treat arguments after the first as fiilenames and print any lines they contain which contain the string specified as the first command line arguments.

When printing lines your program should prefix them with a line number.

It should print suitable error messages if given an incorrect number of arguments or if there is an error opening a file.

e.g. ./fgrep search_string filename1 filename2 filename3
// argc = 1     2            3        4          5
                            ^
                            argv[2]

./fgrep search_string // argc = 2, argv = ["./fgrep", "serach_string"]
                                            argv[0]     argv[1]

argc is an integer, that tells us how many arguments that was passed into the command line.
argv[] is a string array that contains the name of things you inputted into the line. 
*/
#include <stdio.h>
#include <string.h>

#define MAX_LINE 6000
void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // print our error message to std error 
        fprintf(stderr, "usage: %s <search string> < files> \n", argv[0]);  // printing to standard error which prints the error to terminal
        printf("usage: %s <search string> < files> \n", argv[0]);   // printing to the terminal 
        return 1;
    }
    if (argc == 2) {
        // If there is only 1 command-line argument it should read lines from stdin and print them to stdout 
        // search_stream is a unction that seraches the string in the file stream, which is stdin here.
        search_stream(stdin, "<stdin>", argv[1]);
    } else {
        // go through the files we listed and search for search_string 
        for (int i = 2; i < argc; i++) {
            FILE *in = fopen(argv[i], "r");
            // error checking - if the file wasnt opened properly, it will return NULL
            if (in == NULL) {
                fprintf(stderr, "%s: ", argv[0]); //printing an error message to stderr using frpintf 
                // perror preints out the most recent error message correlating to the error no.
                perror(argv[i]);
                return 1;
            }
            // no prblems, seearch in file 
            search_stream(in, argv[i], argv[1]);
        }
    }
    return 0;   // return 0 on success
}
// our parameters: 1. file stream, the name of the stream, and the thing we're looking for 
void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    char line[MAX_LINE];
    int line_number = 1;
    // while we are reading in lines sucessfully.
    while (fgets(line, MAX_LINE, stream) != NULL) {
        // serach for the string in this line. 
        // looking for the string we passed in for the line we just read. 
        if (strstr(line, search_for) != NULL) {
            // we sucessfully found it, we print out the line. 
            // the file wwe ofund it in, line number, and line we read it in
            printf("%s: %d: %s:", stream_name, line_number, line);
        }
        line_number++;
    }
}