#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int n=0, a=0;
	pid_t pid;
    do
    {
        printf("Collatz Conjecture\n\nenter an integer greater than 0\n");
        scanf("%d", &a);
    } while (a <= 0);
    pid = fork();
    if (pid == 0)
    {
        printf("child process...\n");
        printf("%d\n",a);
        while (a>1)
        {
            if (a%2 == 0) a = a/2; //even number
            else if (a%2 == 1) a=3*a+1; //odd number
            printf("%d\n",a);
        }
        printf("child process is finished\n");
    }
    else
    {
        printf("parent process is waiting...\n");
        wait(NULL);
        printf("parent process is finished\n");
    }
	return 0;
}
