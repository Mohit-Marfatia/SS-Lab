/*
============================================================================

Name : 26.c
Author: Mohit Marfatia
Problem: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    execl("./a.out", "./a.out", NULL);
    printf("Some error occured");
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ cc -o b.out 26.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./b.out
Child 1 PID: 6586 is running...
Parent PID: 6585 is waiting for Child 2 PID: 6587 to complete.
Child 2 PID: 6587 is running...
Child 3 PID: 6588 is running...
Child 1 PID: 6586 is exiting.
Child 2 PID: 6587 is exiting.
Parent PID: 6585 detected that Child 2 PID: 6587 has finished.
Parent PID: 6585 detected that Child PID: 6586 has finished.
Child 3 PID: 6588 is exiting.
Parent PID: 6585 detected that Child PID: 6588 has finished.
Parent PID: 6585 is exiting.

*/