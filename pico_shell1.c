#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#define buf_size 100
#define max_args 100
void parse1(char buf[], char *args[], int *n)
{
    *n = 0;

    for (int i = 0; buf[i] != '\0'; i++) {

	while (buf[i] == ' ')
	    i++;

	if (buf[i] == '\0')
	    break;

	args[*n] = &buf[i];
	(*n)++;

	while (buf[i] != '\0' && buf[i] != ' ')
	    i++;

	if (buf[i] == ' ')
	    buf[i] = '\0';
    }

    args[*n] = NULL;
}

void echo1(char *args[], int n)
{
    for (int i = 1; i < n; i++) {

	if (i == (n - 1))
	    printf("%s", args[i]);
	else
	    printf("%s ", args[i]);
    }

    printf("\n");
}

void pwd1()
{
    char buffer[PATH_MAX];
    char *x = getcwd(buffer, PATH_MAX);

    if (x == NULL) {
	printf("system failed\n");
	return;
    }

    printf("%s\n", x);
}

void cd1(char *args[], int n)
{
    if (n < 2) {
	printf("cd: missing argument\n");
	return;
    }

    if (chdir(args[1]) != 0)
	perror("cd");
}

void run1(char *args[])
{
    pid_t pid = fork();

    if (pid < 0) {

	perror("fork");
    }

    else if (pid == 0) {

	execvp(args[0], args);

	perror("execvp");
	exit(1);
    }

    else {

	wait(NULL);
    }
}

int main(int argc, char *argv[])
{
    while (1) {

	char buf[buf_size];
	char *args[max_args];
	int n = 0;

	printf("enta totlob, ana anafez:)");

	if (fgets(buf, buf_size, stdin) == NULL)
	    break;

	if (buf[strlen(buf) - 1] == '\n')
	    buf[strlen(buf) - 1] = '\0';

	if (strlen(buf) == 0)
	    continue;

	parse1(buf, args, &n);

	if (n == 0)
	    continue;

	if (strcmp(args[0], "exit") == 0) {

	    printf("hatw7ashny wallahy :)\n");
	    break;
	}

	else if (strcmp(args[0], "echo") == 0) {

	    echo1(args, n);
	}

	else if (strcmp(args[0], "pwd") == 0) {

	    pwd1();
	}

	else if (strcmp(args[0], "cd") == 0) {

	    cd1(args, n);
	}

	else {

	    run1(args);
	}
    }

    return 0;
}
