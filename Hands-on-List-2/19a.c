/*
============================================================================

Name : 19a.c
Author: Mohit Marfatia
Problem: Create a FIFO file by
a. mknod command
Date: 18th Sept, 2024.
============================================================================
*/

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ mknod my_fifo_mknod p
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ls -l my_fifo_mknod 
prw-rw-r-- 1 mohit-marfatia mohit-marfatia 0 Sep 19 07:06 my_fifo_mknod

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ strace mknod my_fifo_mknod p
execve("/usr/bin/mknod", ["mknod", "my_fifo_mknod", "p"], 0x7ffc8ad1f710 /* 56 vars *) = 0
brk(NULL)                               = 0x56369e676000
...
..
mknodat(AT_FDCWD, "my_fifo_mknod", S_IFIFO|0666)
*/