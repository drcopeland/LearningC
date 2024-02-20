/* Ex. 1-18: Write a program to remove trailing blanks and
tabs from each line of input, and to delete entirely blank lines. */

// WARNING: THIS HAS NOT BEEN TESTED PROPERLY

#include <stdio.h>
#define MAXLINE 1000 // max size for line
#define BLANK 0
#define NOTBLANK 1

void main() {
    int c, i;
    char blanks[MAXLINE]; // char array to keep track of current sequence of blanks
    int linestate;
    

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            blanks[i] = c;
            ++i;
            if (linestate == NOTBLANK)
                putchar(c);
        }
        else if (c != '\n') {
            if (linestate == BLANK)
                printfromarr(blanks, i);
            linestate = NOTBLANK;
            putchar(c);
        }
        else if (c == '\n') {
            if (linestate == NOTBLANK) {
                printfromarr(blanks, i);
                putchar(c);
            }
            linestate = BLANK;
            i = 0;
        }

    }


}

printfromarr(char line[], int len) {
    int i;
    for(i = 0 ; i < len; ++i) {
        putchar(line[i]);
    }
}