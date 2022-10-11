#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include <string.h>

#define MAX_LINE 80

int main(void)
{
	char *arg[MAX_LINE/2+1]; /*command line arguments*/
	int should_run = 1; /*flag to determine when to exit program*/
	
	while(should_run){
		printf("osh>");
		fflush(stdout);
		
		/**
		* your code!
		* After reading user input, the step are:
		* (1) fork a child process using fork()
		* (2) the child process will invoke execvp()
		*/
		
		char *arg[3];
		arg[2] = NULL;
		scanf("%s", arg[0]);
		//printf("test1\n");
		if(getchar() != '\n')
        {
            scanf("%s", arg[1]);
        }
		//printf("test2\n");
		if(!strcmp(arg[0], "exit"))
		{
			//printf("test3\n");
			pid_t pid = fork();
		    if(pid > 0){
		        wait(NULL);
		    }
			else{
		        execvp(arg[0], arg);
	    	}
	    	arg[1] = NULL;
		}
		else
		{
			//printf("test4\n");
			should_run = 0;
		}
		
	}

	return 0;
}


