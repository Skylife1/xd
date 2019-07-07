#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void catcher(int signum){
	puts("El padre puede continuar");
}
int main()
{
	int pid=getpid();
	int fk = fork();
	if (fk != 0)
{
		signal(SIGCONT, catcher);
		pause();
		printf("Soy el padre, Adios\n");
}
	else {
		printf("Hola, Soy el hijo\n");
		kill(pid,SIGCONT);
}
}

