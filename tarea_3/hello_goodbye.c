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
		printf("I'm the father, Goodbye\n");
}
	else {
		printf("Hello, I'm the child\n");
		kill(pid,SIGCONT);
}
}
//En general sin usar la llamada al sistema wait se puede hacer que el hijo se ejecute primero que el padre pero es menos eficiente dado que se pueden usar otras funciones como pause() pero para volver a activar al padre se debe enviar una senal que "mate" al pause()

