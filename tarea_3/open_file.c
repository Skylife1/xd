#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main ()
{
	struct stat sb;
	int fp = open("texto.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	int fk = fork();
	if (fk == 0){
		char hijo[100];
		sprintf(hijo,"Soy el hijo y escribire en este documento \n");
		int esc = write(fp, hijo, strlen(hijo));
		printf("Hijo escribiendo\n");
		exit(0);
}
	else {
		char padre[100];
		sprintf(padre,"Soy el padre y escribire en este documento \n");
		int wr = write(fp, padre, strlen(padre));
		printf("Padre escribiendo\n");
		exit(0);
}
sync();
close(fp);
return(0);
}
//-Ambos procesos pueden acceder al archivo usando open() ya que son procesos diferentes pero la entrada al archivo es "Aleatoria" mientra no se use la llamada al sistema wait()
//-Puede ocurrir que si entran al mismo tiempo se sobrescriban dado que el proceso no tiene la llamada al sistema wait() pero como anteriormente se mencionaba esto es "Aleatorio"

