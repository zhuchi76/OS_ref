#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	printf("Main Process ID : %d\n\n", getpid());
	pid = fork();//1
	if(pid == 0)
	{
		printf("Fork 1. I'm the child %d, my parent is %d.\n", getpid(), getppid());
		
		pid = fork();//4
		if(pid > 0)
		{
			wait(NULL);
		}
		else
		{
			printf("Fork 4. I'm the child %d, my parent is %d.\n", getpid(), getppid());
			
			pid = fork();//5
			
			if(pid > 0)
			{
				wait(NULL);
			}
			else
			{
				printf("Fork 5. I'm the child %d, my parent is %d.\n", getpid(), getppid());
			}
		}
	}
	else
	{
		wait(NULL);
		pid = fork();//2
		if(pid > 0)
		{
			wait(NULL);
		}
		else
		{
			printf("Fork 2. I'm the child %d, my parent is %d.\n", getpid(), getppid());
		}

		pid = fork();//3
		if(pid > 0)
		{
			wait(NULL);
		}
		else
		{
			printf("Fork 3. I'm the child %d, my parent is %d.\n", getpid(), getppid());
		}
	}
	
	return 0;
}
