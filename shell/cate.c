#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[100];
    int i = 0,j,n = 0;
    while ((input[n] = getchar()) != '\n') {
        n++;
    }
    input[n] = '\0';
    while (i < n)
    {
        if(input[i]==' ' && (input[i+1]==' ' || input[i-1]==' '))
        {
            for(j=i;j<n;j++)
            input[j]=input[j+1];
            n--;
        }
        else
        {
            i++;
        }
    }
    printf("%s\n",input);
    printf("\n");
}
