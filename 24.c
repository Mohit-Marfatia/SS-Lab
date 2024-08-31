#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        sleep(5);
        printf("Child process PID: %d, PPID: %d is now orphaned.\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process PID: %d is exiting, leaving child process PID: %d orphaned.\n", getpid(), pid);
        exit(0);
    }

    return 0;
}
/*
Output:
Parent process PID: 20340 is exiting, leaving child process PID: 20341 orphaned.
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ Child process PID: 20341, PPID: 1678 is now orphaned.

*/