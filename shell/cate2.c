#include <stdio.h>
#include <string.h>

int main (void) {

    int c, j, i;

    while ((c = getchar ()) != '\n' && c != EOF)
    {
        if (c == '\r') continue;
        if (c == '\n') {        /* handle newlines/carriage-returns */
            putchar (c);
            while ((c = getchar ()) == '\n' || c == '\r') {}
            if (c != EOF) ungetc (c, stdin); else break;
            continue;
        }
        if (c == ' ' || c == '\t') {  /* spaces & tabs */
            putchar (' ');
            while ((c = getchar ()) == ' ' || c == '\t') {}
            if (c != EOF) ungetc (c, stdin); else break;
            continue;
        }
        putchar (c);
    }
	printf("\n");
    return 0;
}
