#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){
	int x=100;
	int fk = fork();
	if (fk==0){
		printf("Este es el hijo y el valor de x es igual a : %d \n",x);
		x = 459;
		printf("El nuevo valor de x del hijo es x= %d \n", x);
	}

	else {
		//wait(NULL);
		printf("Este es el proceso padre y el valor de x es igual a: %d \n",x);
		x = 534;
		printf("El nuevo valor de x del padre es x= %d \n",x);

}
}
//xd
