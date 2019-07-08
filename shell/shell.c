#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdlib.h>

void actdir(){
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

void listdir(){
	struct dirent *de;
	DIR *dr = opendir(".");
	if (dr == NULL){
		printf("No se puede abrir el directorio");
	}
	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);
	close(dr);
}
//Listar directorios de otra manera
void dir2(){
	char * args[]={"/bin/ls" , NULL};
	execvpe(args[0],args, NULL);
	printf("\n");
}

void clear(){
	const char *CLEAR_SCREEN_ANSI =	"\e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);

}

void camdir(int n, char **fn){

}


int main(int argc, char** argv) {
  char comando[256];
  pid_t pid,pid2;
  while (1) {
    actdir();
    printf("> ");
    gets(comando);
    if (strncmp(comando,"exit",4) == 0) {
      break;
    }
    pid = fork();
    if (pid != 0) {
      wait(NULL);
    } else {
      if (strcmp(comando,"dir") == 0) {
        // listar el contenido de archivos en ese directorio
        printf("debo listar archivos\n");
//	listdir();
	dir2();
	close(STDOUT_FILENO);
      } else if (strcmp(comando, "clear") == 0) {
        printf("Limpiare la pantalla\n");
	clear();
	close(STDOUT_FILENO);
      } else if (strcmp(comando, "cd") == 0){
	printf("Cambiare el directorio");
		int result = 0;
	if (argc >2){
		printf("%s: Muchos operandos",argv[0],argv[0]);
		exit(1);
		}
	if (argc == 1){
		printf("argc is 1\n");
		const char* home = getenv("HOME");
		int i = chdir(home);
		if (i < 0)
			printf("No se puede cambiar el directorio\n");
		else {
			printf("Directorio cambiado con exito\n");
			printf("home = %s\n", home);
		fflush(stdin);
		}
	}
	if(result == 0){
		printf("Directorio cambiado\n");
	}
//	camdir(int argc, char **argv);
        //strtok
        //revisar alguna variante de exec 
        //exec(comando);
      }
    }
  }
  exit(0);
}

