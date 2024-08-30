#include<stdio.h>
#include<unistd.h>
int main(void){
	if(!fork()){
		printf("Process ID of the child is = %d\n", getpid());
	}
	else{
		int status;
		wait(&status);
		printf("Process ID of the parent is = %d \n", getppid());
	}
	return 0;
}
/*
Output:
Process ID of the child is = 16505
Process ID of the parent is = 4538
*/
