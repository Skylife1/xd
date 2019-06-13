#include <stdio.h>

int main(int argc, char** argv){

   int x, y, z;
   x = sizeof(char);
   y = sizeof(int);
   z = sizeof(float);
   
   printf("%d %d %d \n ",x, y, z);
}
