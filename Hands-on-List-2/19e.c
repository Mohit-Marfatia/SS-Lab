/*
============================================================================

Name : 19e.c
Author: Mohit Marfatia
Problem: Create a FIFO file by
e. mkfifo library function
Date: 18th Sept, 2024.
============================================================================
*/
#include<sys/stat.h>

int main() {
	mkfifo("./19e_fifo", 0744);
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ mkfifo my_fifo_mkfifo
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ls -l my_fifo_mkfifo
prw-rw-r-- 1 mohit-marfatia mohit-marfatia 0 Sep 19 07:10 my_fifo_mkfifo


*/