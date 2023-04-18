#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
/* Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process.*/
	FILE *ptr;
	ptr = fopen("Q2open.txt", "w");
	if (ptr == NULL){
		printf("file can't be opened\n");
		exit(1);
	}
        int rc = fork();
        if (rc < 0) {
        	fprintf(stderr, "Fork failed\n");
        	exit(1);
      } else if (rc == 0) {
         // child (new process)
        	fprintf(ptr, "hello, I am child\n");
      } else {
         // parent goes down this path (main)
        	fprintf(ptr, "hello, I am parent\n");
        }
	fclose(ptr);
         return 0;
}
