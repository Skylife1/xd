#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fk = fork();
	if(fk == 0){
		printf("Ejecutando desde el hijo\n");
		char * args[]={"/bin/ls" ,NULL}; //1
		//const char *argv[]={"ls",NULL};//2
		//execvp(args[0],args); // El hijo no tiene por que correr el mismo programa que el padre
		//execv(args[0],args); //Es muy similar a execvp
		execvpe(args[0],args,NULL);

		// Estas representan funciones que funcionan con un vector de punteros por lo cual puede leer la matriz sin tener que digitar los argumentos uno a uno

		//execlp(args[0],args[0],NULL); //Es una funcion matricial 
		//execl(args[0],args[0],NULL); //Es una funcion matricial con casi el mismo funcionamiento que execlp
		//execle(args[0],args[0],args[1],NULL);

		//Estas representan funciones que funcionan con punteros por lo cual hay que darle todos los argumentos de ejecucion para que funcionen

		printf("\n");
}
	else{
		printf("El padre esta de vacaciones (?\n");
		wait(0);
}
}

