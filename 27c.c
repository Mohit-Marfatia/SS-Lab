/*
============================================================================

Name : 27c.c
Author: Mohit Marfatia
Problem: Write a program to execute ls -Rl by the following system calls
c. execle
Date: 31st Aug, 2024.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    char *my_envp[] = { "VAR1=var1", "VAR2=var2", NULL};
    execle("/bin/ls", "ls", "-R","-l", NULL, my_envp);
    printf("There is some error...\n");
    return 0;
}

/*
Output:
.:
total 1088
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1365 Aug 31 18:06  10.c
---------- 1 mohit-marfatia mohit-marfatia     30 Aug 31 18:01  10.text
-rwxr--r-- 1 mohit-marfatia mohit-marfatia     30 Aug 31 18:04  10.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1323 Aug 31 18:08  11.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1129 Aug 31 18:09  12.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1061 Aug 31 18:11  13.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1294 Aug 31 18:13  14.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4215 Aug 31 18:14  15.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1642 Aug 31 18:16  16.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1674 Aug 31 18:20  16b.c
-rw-rw---- 1 mohit-marfatia mohit-marfatia      0 Aug 29 19:05  16temp.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    841 Aug 31 18:24  17.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1747 Aug 31 18:25  17b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    932 Aug 31 18:28  18.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   3371 Aug 31 18:28  18b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    765 Aug 31 18:29  19.c
-rw-rw-r-- 2 mohit-marfatia mohit-marfatia    539 Aug 31 17:14  1a.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    602 Aug 31 17:20  1b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    527 Aug 31 17:29  1c.c
prwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 22 08:41  1c_fifo
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    747 Aug 31 17:41  2.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    953 Aug 31 18:30  20.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    624 Aug 31 18:33  21.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1143 Aug 31 18:34  22.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia     85 Aug 31 00:06  22.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    973 Aug 31 18:34  23.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    971 Aug 31 18:35  24.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   2354 Aug 31 18:35  25.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1221 Aug 31 18:32  26.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4508 Aug 31 18:36  27a.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4576 Aug 31 18:36  27b.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    557 Aug 31 18:37  27c.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4442 Aug 31 07:03  27d.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   4508 Aug 31 07:05  27e.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    779 Aug 31 16:02  28.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1394 Aug 31 16:29  29.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    627 Aug 31 17:41  3.c
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:40  3.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    908 Aug 31 17:05  30.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    687 Aug 31 17:43  4.c
-rwxrwxrwx 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:42  4.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1214 Aug 31 17:47  5.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    866 Aug 31 17:49  6.c
-rw-r--r-- 1 mohit-marfatia mohit-marfatia    866 Aug 31 17:52  6_copy.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    972 Aug 31 17:53  7.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1779 Aug 31 17:58  8.c
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia   1565 Aug 31 17:59  9.c
-rw-rw-rw- 1 mohit-marfatia mohit-marfatia 429969 Jan  3  2021 'Hands-on List 1.pdf'
-rw-rw-rw- 1 mohit-marfatia mohit-marfatia 424747 Jan  3  2021 'Hands-on List II.pdf'
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia  16056 Aug 31 18:37  a.out
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia  16000 Aug 31 06:38  b.out
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia    161 Aug 30 15:30  definition.h
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:44  file0
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:44  file1
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:44  file2
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:44  file3
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 31 17:44  file4
-rw-rw-r-- 2 mohit-marfatia mohit-marfatia    539 Aug 31 17:14  link_example
lrwxrwxrwx 1 mohit-marfatia mohit-marfatia      6 Aug  8 13:48  symlink_example -> ./1c.c
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     40 Aug 31 18:06  temp_dup.txt
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     40 Aug 31 18:06  temp_dup2.txt
-rwxrwxr-x 1 mohit-marfatia mohit-marfatia     20 Aug 31 18:06  temp_fcntl.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia      4 Aug 31 18:25  tickets.txt
-rw-rw-r-- 1 mohit-marfatia mohit-marfatia     48 Aug 31 18:27  train_records.txt

*/