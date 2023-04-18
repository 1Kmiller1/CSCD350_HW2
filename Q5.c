#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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
	int rc_wait = wait(NULL);
        printf("hello (wait = %d)\n", rc_wait);
      } else {
         // parent goes down this path (main)
        int rc_wait = wait(NULL);
        printf("Goodbye (wait = %d)\n", rc_wait);
        }
         return 0;
}
