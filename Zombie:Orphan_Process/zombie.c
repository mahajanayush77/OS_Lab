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
printf("Child process terminated\n Now I am a zombie!\n");

}

else 
{
sleep(10);
printf("Parent Process terminated\n");

}

return 0;

}