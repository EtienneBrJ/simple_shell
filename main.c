#include "shell.h"

int main(int argc, char *argv[100], char *env[])
{
	int pid;
	char *buffer;
	char* path= "/bin/";
	char progpath[20];
	size_t bufsize = 0;
	int i=0;
	char *token;
	size_t length;

	(void)argc;
        (void)env;

	while(1)
	{
		printf("$ ");

		if(getline(&buffer, &bufsize, stdin) == -1)
		{  /**get command and put it in line*/
			break;             /**if user hits CTRL+D break*/
		}
		length = _strlen(buffer);
		if (buffer[length - 1] == '\n')
			buffer[length - 1] = '\0';

		
		token = strtok(buffer, " ");
		
		while(token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL," ");
			i++;
		}
		argv[i] = NULL;       /**set last value to NULL for execvp*/

		argc = i;                           /**get arg count*/
		for(i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);      /**print command/args*/
		}
		_strcpy(progpath, path);           /**copy /bin/ to file path*/
		_strcat(progpath, argv[0]);            /**add program to path*/

		pid = fork();              /**fork child*/

		if(pid == 0)
		{               /**Child*/
			execvp(progpath,argv);
			fprintf(stderr, "Child process could not do execvp\n");
			
		}
		else
		{                    /**Parent*/
			wait(NULL);
			printf("Child exited\n");
		}



	}
	return(0);
}
