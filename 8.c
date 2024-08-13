/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/
#include<stdio.h>
#include<fcntl.h>

int main(){
	int source_file = open("./7.c", O_RDONLY);
	perror("Read from source file: ");

	int buffer_size = 2048;
	char buffer[buffer_size];

	while(read(source_file, buffer, 1)){
		if(buffer[0]=='\n') getchar();
		else printf("%c", buffer[0]);
	}
	
	close(source_file);
}
