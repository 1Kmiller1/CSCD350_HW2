#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
/* Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100).*/
	int x = 100;
	int rc = fork();
	if (rc < 0) {
	fprintf(stderr, "Fork failed\n");
	exit(1);
      } else if (rc == 0) {
 	 // child (new process)
	x = 12;
	printf("hello, I am child (pid:%d)\n", (int) getpid());
	printf("printing %d\n", x);
      } else {
	 // parent goes down this path (main)
	x = 50;
	printf("hello, I am parent of %d (pid:%d)\n",rc, (int) getpid());
	printf("printing %d\n", x);
	}
	 return 0;
}
