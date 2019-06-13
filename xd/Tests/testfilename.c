#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()

{
   char file [100];
   int c;
   printf ("Nombre del archivo: ");
   scanf ("%s", file);

      if (access( file, F_OK ) != -1) {
    //file exists
         printf("El archivo existe \n ");
         fp = fopen ("file" , "r");
         c=getc(fp); 
         printf("%c",c);
         fclose(fp);
         return(0);
} 
     else {
    //file doesn't exist
        printf("El archivo no existe \n ");
}
}
