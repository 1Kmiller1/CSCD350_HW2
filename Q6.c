#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
/*Write a slight modification of the previous program, 
this time using waitpid() instead of wait().*/
        int rc = fork();
        if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
      } else if (rc == 0) {
         // child (new process)
        printf("hello\n");
      } else {
         // parent goes down this path (main)
        int rc_wait = waitpid(rc, NULL, 0);
        printf("Goodbye (wait = %d)\n", rc_wait);
        }
         return 0;
}
