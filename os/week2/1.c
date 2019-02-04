#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int status,pid;
	pid = fork();
	if(pid == -1)
	{
		printf("Child Unsuccessful\n");
		exit(1);
	}

	if(pid == 0)
		printf("Child Successful\n");
	else
	{
		wait(&status);
		printf("Parent Created\n");
	}
	return 0;
}