#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    char *my_envp[] = { "VAR1=var1", "VAR2=var2", NULL};
    execle("/bin/ls", "ls", "-R","-l", NULL, my_envp);
    printf("There is some error...\n");
    return 0;
}