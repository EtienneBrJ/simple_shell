#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
void ctrlc(int i)
{
	i = i;
	write(1,"dans la fonction\n", 17);
}

int main()
{
	char *argv[100];
	char *token;
	char *buffer = NULL;
	size_t bufsize = 0;
	int characters;
	pid_t pid;
	int i = 0;
	char* path= "/bin/";
	char progpath[20];

	do
	{
		signal(SIGINT, ctrlc);

//		printf("----------------------------------------\n");
/*		my_pid = getpid();
 *		printf("pid: %u\n", my_pid);
 *		my_pid = getppid();
 *              printf("ppid: %u\n", my_pid);
 */
		write(1, "$ ",2);

		characters = getline(&buffer, &bufsize, stdin);

//		printf("%s\n", buffer);

		token = strtok(buffer, " ");
		while(token != NULL)
		{
//			printf("arg: %s\n",token);
			argv[i] = token;
			token = strtok(NULL," ");
			i++;
		}
//		printf("%i characters\n", characters);
		argv[i] = NULL;

		strcpy(progpath, path);
		strcat(progpath, argv[0]);

		if (pid == fork() == 0)
			if ((execvp(progpath, argv) == -1))
				perror("Execvp == -1: Error");
			else
			{
				wait(NULL);
				printf("Child a finit");
			}
	} while (buffer != NULL && characters != -1);

	free(buffer);
	printf("exit sucsess !!\n");
	return(0);
}
