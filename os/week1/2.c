#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include <conio.h>
int main()
{	
	pid_t pid;
	int n;
	pid = fork();
	printf("Process Running with initial pid = %d\n",pid);

	pid = getpid();
	printf("Process Running with pid = %d\n",pid);
	scanf("%d",&n);
	return 0;
}