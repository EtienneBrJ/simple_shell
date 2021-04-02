#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_LEN 1024

int main(int argc, char *argv[100], char *env[])
{
	int pid;
	char *buffer;
	char* path= "/bin/";
	static char progpath[20];
	size_t bufsize = 0;
	int i = 0;
	char *token;
	size_t length;

        (void)env;

	while(1)
	{
		printf("$ ");

		if(getline(&buffer, &bufsize, stdin) == -1)
		{
			break;
		}
		if(strcmp(buffer, "exit") == 0)
		{
			break;
		}
		length = strlen(buffer);
		if (buffer[length - 1] == '\n')
			buffer[length - 1] = '\0';

		token = strtok(buffer, " ");
		while(token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL," ");
			i++;
		}
		argv[i] = NULL;

		argc = i;
		for(i = 0; i < argc; i++)
		{
			printf("%s <- args || pid :%d || ppid :%d\n", argv[i], getpid(), getppid());
		}
		strcpy(progpath, path);
		strcat(progpath, argv[0]);

		pid = fork();

		if (pid == 0)
		{
			/**Child*/
                        execvp(progpath,argv);
                        fprintf(stderr, "Child process could not do execvp\n");
		}
		else
		{  /**Parents*/
			wait(NULL);
			printf("Child exited");
		}

	}
	free(buffer);
	return(0);
}
