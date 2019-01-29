#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	pid_t n;
	
	n = fork();

	//wait(NULL); // waits for child to complete first
	
	if(n)
		printf("Parent process with fork: %d and getpid: %d\n", n,getpid());
	else
		printf("child process with fork: %d and getpid: %d\n", n,getpid());

	return 0;
}