#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	pid_t cpid;
	int status;
	if(fork() == 0)
	{
		printf("Child id: %d\n", getpid());
		exit(69);								// 69 modulo 256
	}
	else
	{
		cpid = waitpid(0, &status, WUNTRACED /*or WNOHANG*/);
		// cpid = wait(&status);
		printf("Parent id: %d\n", getpid());
		printf("Child id: %d\n", cpid);
		//----------------------------------------------------------------------------------------------------------
		printf("WEXITSTATUS : %d\n", WEXITSTATUS(status));
		printf("WIFEXITED : %d\n", WIFEXITED(status));
		printf("WIFSIGNALED : %d\n", WIFSIGNALED(status));
		printf("WTERMSIG : %d\n", WTERMSIG(status));		
		printf("status : %d\n", status);
		//-----------------------------------------------------------------------------------------------------------
	}
	return 0;
}