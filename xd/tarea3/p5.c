#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (){

	int fk = fork();
	if (fk != 0){
//		int w = wait(0);
		printf("Soy el padre y voy primero \n");
}
	else {
//		int w = 0;
		int w = wait(0);
		printf("Soy el hijo y voy de segundo y el wait() que tengo arroja %d\n",w);

}
}
 
