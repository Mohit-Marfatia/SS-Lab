#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    execl("/bin/ls", "ls", "-R","-l", NULL);
    printf("There is some error...\n");
    return 0;
}

/*
Output:
.:
total 1040
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    387 Aug 18 16:01  10.c
-rwxr--r-- 1 mohit-marfatia mohit-marfatia     30 Aug 18 16:02  10.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1073 Aug 20 23:00  11.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    832 Aug 21 14:40  12.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    406 Aug 21 15:26  13.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    787 Aug 22 08:51  14.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4040 Aug 28 18:40  15.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    738 Aug 29 23:48  16b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1677 Aug 30 14:06  16.c
-rw-rw---- 1 mohit-marfatia mohit-marfatia      0 Aug 29 19:05  16temp.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1025 Aug 30 15:26  17b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    264 Aug 30 15:08  17.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   2922 Aug 30 22:47  18b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    386 Aug 30 22:23  18.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    391 Aug 31 00:05  19.c
-rw-rw-r-- 2 mohit-marfatia mohit-marfatia    261 Aug  8 13:40  1a.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    250 Aug  8 13:51  1b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia     73 Aug 22 08:40  1c.c
prwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 22 08:41  1c_fifo
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    638 Aug 30 04:26  20.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    325 Aug 30 04:29  21.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    769 Aug 31 00:12  22.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia     85 Aug 31 00:06  22.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    679 Aug 31 00:21  23.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    697 Aug 31 00:38  24.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   2003 Aug 31 06:16  25.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    813 Aug 31 06:39  26.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4497 Aug 31 06:46  27a.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    282 Aug  8 09:19  2.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    316 Aug  8 15:10  3.c
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 23:25  3.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    399 Aug  8 15:23  4.c
-rwxrwxrwx 1 mohit-marfatia mohit-marfatia      0 Aug  8 23:24  4.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    446 Aug  8 22:49  5.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    555 Aug 22 08:30  6.c
-rw-r--r-- 1 mohit-marfatia mohit-marfatia    555 Aug 22 09:14  6_copy.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    708 Aug 22 09:14  7.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    519 Aug 13 15:30  8.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1113 Aug 18 16:51  9.c
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia  16000 Aug 31 06:47  a.out
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia  16000 Aug 31 06:38  b.out
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    161 Aug 30 15:30  definition.h
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file0
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file1
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file2
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file3
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file4
-rw-rw-rw- 1 mohit-marfatia mohit-marfatia 429969 Jan  3  2021 'Hands-on List 1.pdf'
-rw-rw-rw- 1 mohit-marfatia mohit-marfatia 424747 Jan  3  2021 'Hands-on List II.pdf'
-rw-rw-r-- 2 mohit-marfatia mohit-marfatia    261 Aug  8 13:40  link_example
lrwxrwxrwx 1 mohit-marfatia mohit-marfatia      6 Aug  8 13:48  symlink_example -> ./1c.c
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     40 Aug 20 22:52  temp_dup2.txt
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     40 Aug 20 22:52  temp_dup.txt
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     20 Aug 20 22:52  temp_fcntl.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia      4 Aug 30 17:07  tickets.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia     48 Aug 30 22:45  train_records.txt

*/