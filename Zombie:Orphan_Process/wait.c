#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

int pid = fork();

if(pid == 0)
{
printf("Child process terminated\n");

}

else 
{
wait(0);
printf("Parent process");

}

return 0;

}