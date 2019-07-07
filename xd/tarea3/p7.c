#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int fk = fork();
	if (fk != 0){
		wait(0);
		printf("Soy el proceso supremo lmao\n");
		}
	else{
		close(STDOUT_FILENO);
		printf(":(");
		}
}
