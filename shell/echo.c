#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int echo();

int main(){
	echo();
	return 0;
	}

int echo(){
	char input[512];
	while(fgets(input, 512, STDIN)){
		printf("%s\n", input);
		memset(input, 0, strlen(input));
		}
	return 1;
	}
