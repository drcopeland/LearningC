#include <stdio.h>

#define TABSIZE 8

main() {
    int c;
    int d, i; // distance until next tab stop

    d = 0;

    while((c = getchar()) != EOF) {
        if (c != '\t') {
            putchar(c);
            d = (d + TABSIZE - 1)%TABSIZE;
        }
        else {
            if (d == 0) { // if we're at a tab stop, add blanks to the next tab stop
               for(i = 0; i < TABSIZE; ++i)
                    putchar(' '); 
            }
            for( ; d != 0; d = (d-1)%TABSIZE) // otherwise add blanks until d = 0
                putchar(' ');
        }
    }
}