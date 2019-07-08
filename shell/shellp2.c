#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_clear(char **args);
int lsh_dir(char **args);
int lsh_environ();
int lsh_pause();

char *builtin_str[] = {
	"cd",
	"help",
	"quit",
	"clr",
	"dir",
	"environ",
	"pause"
	};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit,
	&lsh_clear,
	&lsh_dir,
	&lsh_environ,
	&lsh_pause
	};

int lsh_num_builtins(){
	return sizeof(builtin_str) / sizeof(char *);
	}

int lsh_cd(char **args){
	if (args[1] == NULL){
		fprintf(stderr, "lsh: Se espera un argumento para \"cd\"\n");
	}else {
		if (chdir(args[1]) != 0){
		perror("Shell");
			}
		}
	return 1;
	}

int lsh_help(char **args){
	int i;
	printf("Shell de Mario Londono y Camilo Hoyos\n");
	printf("USAR BAJO SU PROPIO RIESGO\n");
	printf("Escribir los argumentos y nombres respectivos y undir enter\n");
	printf("Los argumentos programados son:\n");
	for (i = 0; i < lsh_num_builtins(); i++) {
		printf(" %s\n", builtin_str[i]);
		}
	printf("Usar el comando man para informacion en otros programas, sorry\n");
	return 1;
	}


int lsh_actdir(){
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s",cwd);
	return 1;
}


int lsh_clear(char **args){
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	return 1;
}


int lsh_dir(char **args){
	int fk = fork();
	if (fk == 0){
		char * args1[]={"/bin/ls", NULL};
		execvp(args1[0], args1);
		printf("\n");
	}else{
		wait(NULL);
	}
	return 1;
}

int lsh_pause(){
	char ch;
	printf("Pausando...\n");
	printf("Presiona una tecla para continuar\n");
	scanf("%c", &ch);
	printf("Reanudando");
	}

int lsh_exit(char **args){
	return 0;
}

extern char **environ;

int lsh_environ(){
	for(char **env = environ; *env; env++){
		printf("%s \n",*env);
		}
	return 1;
	}


int lsh_launch(char **args){

	pid_t pid, wpid;
	int status;
	pid = fork();
	if (pid == 0){
		if (execvp(args[0], args) == -1){
			perror("Shell");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0){
		perror("Shell");
	} else { //proceso del padre
		do{
		wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}


int lsh_execute(char **args){
	int i;
	if (args[0] == NULL) {
		return 1;
		}
	for (i = 0; i < lsh_num_builtins(); i++){
		if (strcmp(args[0], builtin_str[i]) == 0){
			return (*builtin_func[i])(args);
			}
		}
	return lsh_launch(args);
	}


char *lsh_read_line(void){
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **lsh_split_line(char *line){
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;
	if(!tokens){
		fprintf(stderr,"Error de locacion\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, LSH_TOK_DELIM);
	while (token !=NULL){
		tokens[position] = token;
		position++;
		if (position >= bufsize){
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize *sizeof(char*));
			if (!tokens){
				fprintf(stderr, "Error de localizacion\n");
				exit(EXIT_FAILURE);
				}
			}
		token = strtok(NULL, LSH_TOK_DELIM);
		}
	tokens[position] = NULL;
	return tokens;
}


void lsh_loop(void){
	char *line;
	char **args;
	int status;
	do {
		lsh_actdir();
		printf(" ~$> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);
	free(line);
	free(args);
	} while (status);
}



int main(int argc, char **argv){

	lsh_loop();

	return EXIT_SUCCESS;
}
