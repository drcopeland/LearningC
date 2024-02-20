/* Ex. 1-21: Write a prograb 'entab' that replaces strings
of blanks by the minimum number of tabs and blanks to achieve
the same spacing. Use the same tab stops as for detab.
*/

#include <stdio.h>

#define TABSIZE 8
#define IN 0
#define OUT 1


main() {
    int blankcount, c, state, pos;

    blankcount = pos = 0;

    while((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') {
            if (state == OUT) {
                makeblanks(blankcount, (pos -blankcount) % TABSIZE);
                blankcount = 0;
            }
            putchar(c);
            state = IN;
            
            if (c == '\n')
                pos = 0;
            else
                pos = (pos + 1) % TABSIZE;
        }
        else if ( c == ' ') {
            ++blankcount;
            pos = (pos + 1) % TABSIZE;
        }
        else if (c == '\t') {
            blankcount += TABSIZE - pos;
            pos = 0;
        }
        state = OUT;
        
    }
}

/* makeblanks: starting at p mod TABSIZE,
print tabs and blanks to account for a total of n columns, using
a minimal number of tabs and blanks. */
makeblanks(int blankcount, int p) {
    int nb, nt;

    p = p % TABSIZE;
    // Case 1: no tabs
    if (p + blankcount < TABSIZE) {
        for (nb = 0; nb < blankcount; ++nb)
            putchar(' ');
    }

    // Case 2: at least one tab
    else {
        putchar('\t');
        makeblanks(blankcount - TABSIZE + p, 0);
    }
}