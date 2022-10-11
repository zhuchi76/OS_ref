#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sstream>

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
		
        string cmd;
        istringstream is;
		int argc = 0;
		getline(cin, cmd);
        is.str(cmd);
    	for (unsigned i = 0; i <= cmd.length(); i++)
		{
			if (cmd[i] == ' ' || cmd[i] == '\0')
			{
				argc++;
			}
		}

		string arr[argc+1];
		for (int i = 0; i < argc; i++)
		{
			is >> arr[i];
		}

		//cout << "test\n";
		if(arr[0].compare("exit"))
		{
			pid_t pid = fork();
		    if(pid > 0){
		        wait(NULL);
		    }
			else{
				for (int i = 0; i < argc; i++)
				{
					arg[i] = const_cast<char*>(arr[i].c_str());
				}
				arg[argc] = NULL;
		        execvp(arg[0], arg);
	    	}
		}
		else
		{
			should_run = 0;
		}
		
	}

	return 0;
}