#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

int pid = fork();

if(pid == -1) {

	printf("Cannot create a process\n");
	exit(1);
	}

else if(pid == 0)
{
sleep(10);
printf("Now I am an orphan my parent process died!\nChild process terminated\n" );

}

else 
{

printf("Parent Process terminated\n");

}

return 0;

}