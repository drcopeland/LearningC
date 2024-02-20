#include <stdio.h>

/* Ex. 1-23: Write a program to remvove all comments from
a C program. */


#define OUT 0
#define INSINGLE 1
#define INMULTI 2
#define INQUOTE 3
#define INDOUBLEQUOTE 4
#define MAYBESLASH 5
#define MAYBESTAR 6

main () {
    int c;
    int state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (state == OUT) {
            if (c != '/' && c != '\'' & c != '\"') {
                putchar(c);
            }
            else if (c == '/') {
                state = MAYBESLASH; // if the next charater is * or /, become a comment
            }
            else if (c == '\'') {
                state = INQUOTE;
                putchar(c);
            }
            else if (c == '\"') {
                state = INDOUBLEQUOTE;
                putchar(c);
            }
        }

        else if (state == MAYBESLASH) {
            if (c == '/') {
                state = INSINGLE;
            }
            else if (c == '*') {
                state = INMULTI;
            }
            else {
                putchar('/'); // not a comment, replace the slash
                putchar(c); 
            }
        }

        else if (state == INSINGLE) { // in single line comment, just continue until end of line
            if (c == '\n') {
                putchar(c);
                state = OUT;
            }
        }
        else if (state == INMULTI) { // in multi line comment, wait for a *
            if (c == '*') {
                state = MAYBESTAR;
            }
        }
        else if (state == INQUOTE) { // in quote, wait for a '
            if (c == '\'') {
                state = OUT;
            }
            putchar(c);
        }
        else if (state == INDOUBLEQUOTE) { // in double quote, wait for "
            if (c == '\"') {
                state = OUT;
            }
            putchar(c);
        }
        else if (state == MAYBESTAR) { // if char is / , this ends a multiline comment
            if (c == '/') {
                state = OUT;
            }

        }
    }

}