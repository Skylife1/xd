#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid,pid2;
	int status;
	pid = fork();
	if (pid != 0){
//		pid2 = waitpid(pid, &status, 0);
		printf("Soy el padre y voy primero \n");
		printf("El pid proceso: %d\n",getpid());
		printf("El pid es:%d\n",getppid());
	}

	else {
//		sleep(3);
		printf("Soy el hijo y voy segundo \n");
//		printf("El pid es %d ", pid);
//		pid2 = waitpid(pid, &status, 0);
		int w = waitpid(getppid(), &status, 0);
		printf("El waitpid es %d\n", w);
		printf("El pid del proceso es: %d\n",getpid());
		printf("El pid es padre: %d \n",getppid());
	}
	return 0;
}

//Seguira sucediendo lo mismo que en el punto 5 dado que el hijo no tiene un hijo que esperar
