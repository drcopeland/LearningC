#include <stdio.h>



#define N 10
#define TABSIZE 8
#define IN 1
#define OUT 0

/*
NOTE: current version has only been tested on tab-less text, 
but works "in theory".
*/

main() {
    int c; // variable to hold input chars
    int i; // counter to measure current newline length
    int j;
    int blankpos; // starting position of most recent sequence of blanks
    char newline[N]; // char array to store newline
    int state;

    blankpos = i = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (i < N) {
            if (c == '\n') {
                printline(newline, i);
                blankpos = i = 0;
                state = OUT;
            }
            else if (c != ' ') {
                newline[i] = c; // place the char into the line so far
                state = IN;
                ++i;
            }
            else if (c == ' ') {
                if (state == IN) {
                    blankpos = i;
                }
                newline[i] = c;
                state = OUT;
                ++i;
            }
            else if (c == '\t') {
                if (state == IN) {
                    blankpos = i;
                }
                if (i + TABSIZE - (i % TABSIZE)< N) {
                    for ( ; i % TABSIZE != 0 ; ++i) {
                        newline[i] = ' '; // we replace tabs with spaces to avoid counting tabs
                    }
                }
                else { // if the tab goes over the limit, we end the line with spaces and start the new line with the next c
                    for ( ; i < N ; ++i) {
                        newline[i] = ' ';
                    }
                }
                state = OUT;
            }
        }
        else { // when i = N ie we need to start a new line
            if (blankpos > 0) { // a blank occurred
                printline(newline, blankpos); // print the line up to blankpos
                // need the newline to start with the unexamined chars
                char temp[N];
                for (i = blankpos + 1; i < N; ++i) {
                    temp[i - blankpos-1] = newline[i]; //fill a temp array
                }
                for (i = 0; i < N - blankpos - 1; ++i)
                {
                    newline[i] = temp[i]; // set the next newline
                }
                newline[i] = c;
                
                if (c == ' ')
                    blankpos = i;
                else if (c == '\t')
                    blankpos = TABSIZE;
                else 
                    blankpos = 0;
                ++i;
            }
            else {
                if (c == ' ' || c == '\t') {
                    printline(newline, N);
                }
                else {
                    for (i = 0; i < N; ++i) {
                        putchar(newline[i]);
                    }
                    printf("<br>\n"); // place a <br> to chop the line
                    blankpos = 1;
                }
                newline[0] = c; // put the char we read into the next line
                i = 1;
                
                
            }
        }
    }
        
}

// print the first K char in line (not including '\n' at the end) and include '\n'

printline(char line[], int K) {
    int i;

    for (i = 0; i < K; ++i) {
        putchar(line[i]);
    }
    putchar('\n');
}

