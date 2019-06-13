#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reverse (char *array[]){
	int length = strlen(array);
        int x;
	for (x = length - 1; x >= 0; x--){
		if (array[x] == ' '){
			array[x] = '\0';
			printf("%s ",&(array[x])+ 1);
}
}
	printf("%s ", array);
}
int main (int argc, char *argv[])
{
   int c,i;
   char file [100];
   printf("Digite el nombre del archivo: ");
   scanf("%s", file);
   FILE* fp=fopen(file, "r");
   if (fp==NULL){
      printf("Can't open the file \n");
      return 1;
}
   char output [256];
   for (c = 1; fgets(output, sizeof(output),fp) != NULL; c++)
{
      printf("%02d: %s",c);
}
   printf("The reverse of the text is: \n");

   for (i = 1; fgets(output, sizeof(output),fp) != NULL; i++){
	reverse(fgets(file, 100, fp)!=NULL );
}
   fclose(fp);

   return 0;
}
