What is your tutor's name, e-mail, how long have they been at UNSW, what are they studying, what is 1 interesting thing about them?
What are your class mates's names, what are they each studying, what is 1 interesting thing about each of them?
Are there any marks for attending lectures, tutorials or labs?
Where is the CSE Help desk and what do they help with?
How do I find COMP1911 on Moodle?
What is an operating system?
What operating systems are running in your tute room?
What operating system do CSE lab computers run?
On windows, is the control panel and file explorer part of the list of applications, or part of the operating system?
What is a file in the context of computers? What kind of files are used in COMP1911?





What is a file extension? Do they matter?
- A file extension is usually a suffix to a file name (after a ".") that tells an operating system what "type" of file it is. 
- a OS uses this to know what application to open this file in. 
- changing the file extension, does not change the file itself or the contents.

10. If I have written a fantastic C program in a file named stuff.c how could I execute it to show it off to my friends?
- the computer doesnt understand C code!! Code is for us humans. 
- you need to compile the code, using dcc, or gcc to creating machine code that the computer can understand and execute.

the commands to do this on a cse machine:
compile:  dcc stuff.c -o stuff 
execute: ./stuff 

or
gcc -Wall -Werror -O stuff.c -o stuff
./stuff

11. What is the difference between gcc and dcc?
- dcc and gcc bother translate c programs -> machine code which can be executed by the computer
- dcc can detect more errors and gives more helpful error messages than gcc.
- With gcc it is advised to run with the flags -Wall -Werror and -O to give more help with compile errors. dcc already does that for us anyway but is even more helpful.

- COMP1911 will use dcc. MAKE SURE YOUR CODE SUBMISSIONS CAN RUN AND COMPILE USING DCC. 


12. What is a text file? Give examples of text and non-text files.
- A TEXT FILE IS A FILE CONTAINING represenations of alphabetical characters of a particular language. 
- It is designed to contain information that can be read when opened by a program. An example is the source to a C program.
- a non text file: the machine code file produced by gcc or dcc

13. What is an editor used for in COMP1911? How many editors are installed on CSE lab machines? Which one is recommended for COMP1911 students?
- you use an editor to create and modify the text of your C programs

14. What is machine code? Why does a COMP1911 student need machine code, how to they create it and where to they keep it?
- machine code is the binary instructions that can be directly processed by the CPU (central processing unit) of a computer
- we need machine code so that we can execute the programs we written
- we can get machine code by creating a C program then using dcc or gcc to translate into machine code 
 C code -> dccc/gcc -> machine code 

 - keep machine code in files. if you dont specific a file, dcc/gcc will put the machine code in a file named a.out 


15. What are some basic Linux commands do you need to know to do the complete the first COMP1911 labs, and what do they do?
gedit - a simple text editor to create C program files
dcc - translates C programs to machine code which can be executed
ls - it lists the files in the current directory 
cp - copy a file 
rm - remove a file 
mkdir - create a directory 
cd - change your current directory. 

16. 
// Author: Hayden Smith (hsmith@unsw.edu.au)
// Date created: February 2019
// My first C program

#include <stdio.h>

int main (void) {
    // printf prints something tot he terminal 
    printf ("COMP1911 is my favourite computing course!\n");

    return 0;
}
/*
// the \n: stands for new line. 
//it output a new line at the end of the line, agter 
COMP1911 is my favourite computing course!

// or /*  are comments = makes your code easier to read for humans. 
makes your code easier to understand for humans. 
An example of a comment is a header comment. You should make sure you have a header comment with your name, date and the purpose of your program at the top of every program you write.

indenting:
- help us read the code
- implies the control structure and the scope and logic
- indent after  {}
- helps with readbility. 
*/

17. Is the style-guide a good recommendation for how to write clean code?
- Yes. However, in COMP1911 it is not just a recommendation, but also a requirement. Please write all of your code with strict adherence to the style guide.

18. please see tutorial recording if you didn't follow along! (hopefully you paid attention)