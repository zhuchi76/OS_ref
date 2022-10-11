#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

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
		
        char a[MAX_LINE/2+1];
        arg[1] = NULL;
		arg[2] = NULL;
		scanf("%s", arg[0]);
        //printf("s1:%s\n", arg[0]);

        //arg[1] = "-f";
		if(cin.peek() != '\n')
        {
            scanf("%s", a);
            //printf("s0:%s\n", a);
            arg[1] = a;
            //printf("s0:%s\n", arg[1]);
        }

		if(strcmp(arg[0], "exit"))
		{
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
			should_run = 0;
		}
		
	}

	return 0;
}