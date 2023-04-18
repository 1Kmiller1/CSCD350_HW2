#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
/* Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100).*/
        int rc = fork();
        if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
      } else if (rc == 0) {
         // child (new process)
        printf("hello\n");
      } else {
         // parent goes down this path (main)
	for (int x = 0; x < 2000000 ; x++){
	x++;}
        printf("Goodbye\n");
        }
         return 0;
}
