/*
*/

#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
        while(1){
            sleep(4);
            printf("Child pid: %d\n", getpid());
            printf("Daemon process is running...\n");
        }
    } else{
        exit(0);
    }
}

/*
Output:
Child pid: 8230
Daemon process is running...
Child pid: 8230
Daemon process is running...
Child pid: 8230
Daemon process is running...
Child pid: 8230
Daemon process is running...
^C
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ Child pid: 8230
Daemon process is running...
Child pid: 8230
Daemon process is running...
Child pid: 8230

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ps -el | grep 8230
1 S  1000    8230    1686  0  80   0 -   654 hrtime ?        00:00:00 a.out

*/