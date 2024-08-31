/*
============================================================================
Name : 8.c
Author : Mohit Marfatia
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 13th Aug, 2024.
============================================================================
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

/*
Output:
Read from source file: : Success
/*
============================================================================
Name : 7.c
Author : Mohit Marfatia
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 13th Aug, 2024.
============================================================================
*/

// #include<stdio.h>
// #include<stdlib.h>
// #include<fcntl.h>

// int main(int argc, char *argv[]){
// 	int source_file = open(argv[1], O_RDONLY);
// 	perror("Read from source file: ");
// 	if(source_file < 0){
// 		exit(0);
// 	}
// 	int dest_file = open(argv[2], O_CREAT | O_RDWR, 0600);

// 	//int buffer_size = 1024;
// 	char buffer[1024];

// 	int bytes_read, bytes_written;
// 	while((bytes_read = read(source_file, buffer, sizeof(buffer))) > 0) {
// 		write(dest_file, buffer, bytes_read);
// 	}
// 	//perror("Bytes read from source file: ");
// 	printf("Write success\n");
// 	//perror("Bytes written from source file: ");
// 	close(source_file);
// 	close(dest_file);

// }

/*
Output:
Read from source file: : Success
Write success

*/