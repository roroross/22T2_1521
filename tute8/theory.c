Q14.
Consider the lseek(fd, offset, whence) function.

What is its purpose?
- allows you to reposition the file pointer to the offset you want it to be at 
When would it be useful?
- when you wanna read or write from a specific position
What does its return value represent?
- returns the file position in bytes after you finish lseek, else, it returns -1 if lseek() failed. 

Q15: Consider a file of size 10000 bytes, open for reading on file descriptor fd, initially positioned at the start of the file (offset 0). What will be the file position after each of these calls to lseek()? Assume that they are executed in sequence, and one will change the file state that the next one deals with.

lseek(fd, 0, SEEK_END);
- moving the file position to the end of the file at offset 10000
- SEEK_END - at the end of the file 
lseek(fd, -1000, SEEK_CUR);
- SEEK_CUR is the current position of the file
- here, currently were at offset 10000
- lseek(fd, -1000, SEEK_CUR) --> makes us go back 1000 bytes from our current position at 10000

now, our current position after lseek is at 9000 bytes into the file

lseek(fd, 0, SEEK_SET);
- SEEK_SET = moves it to the beginning of file 
= move my file pointer 0 bytes from the beginning of the file
- curr position = 0 bytes 

lseek(fd, -100, SEEK_SET);
= i wanna go backwards 100 byes from the beginning of the file. 
- but u cant, the position is unchanged. 

lseek(fd, 1000, SEEK_SET);
= moves 1000 bytes from the start of the file
curr position @ 1000 bytes 

lseek(fd, 1000, SEEK_CUR);
= moves 1000 bytes from the current which is 1000 bytes rn
curr position is now 2000 bytes 