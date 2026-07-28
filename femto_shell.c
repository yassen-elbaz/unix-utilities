#include<stdio.h>
#include <unistd.h>
#include <string.h>
#define buf_size 100
int main(int argc, char *argv[])
{
    while (1) {
	char buf[buf_size];
	printf("femto_shell is in ur service: ");
	fgets(buf, buf_size, stdin);
	if (buf[strlen(buf) - 1] == '\n')
	    buf[strlen(buf) - 1] = 0;
	if (strlen(buf) == 0)
	    continue;
	if (strcmp(buf, "exit") == 0) {
	    printf("goodbye\n");
	    break;
	}
	if (strncmp(buf, "echo", 4) == 0) {
	    printf("%s\n", buf + 5);

	} else {

	    printf("invalid command\n");
	}
    }








    return 0;
}
