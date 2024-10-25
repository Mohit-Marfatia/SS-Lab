/*
============================================================================

Name : 19b.c
Author: Mohit Marfatia
Problem: Create a FIFO file by
c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 18th Sept, 2024.
============================================================================
*/


/*
Output:

By analyzing the output, we see that mkfifo uses the mknod system call internally to create the FIFO. 
This implies that mkfifo is just a higher-level library function that simplifies the usage of mknod for this specific purpose.

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ strace mkfifo my_fifo_mkfifo
execve("/usr/bin/mkfifo", ["mkfifo", "my_fifo_mkfifo"], 0x7fff186a6658 /* 56 vars *) = 0
brk(NULL)                               = 0x5623929d8000
...
..
mknodat(AT_FDCWD, "my_fifo_mkfifo", S_IFIFO|0666)


*/