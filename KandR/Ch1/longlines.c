/* Ex. 1-17: Write a program to print all input lines
that are longer than 80 characters. */


/*
while(lines are in file)
    if (it's longer than 80 chars)
        print it
*/
#include <stdio.h>

#define MINLINE 5
#define MAXLINE 1000

main() {
    int c;
    int len = 0; // current length of line
    char line[MAXLINE]; // save the current line in a char array

    while((c = getchar()) != EOF) {
        line[len] = c;
        ++len;
        
        if ((c == '\n') || (len == MAXLINE - 1)) { // once we get to the end of a line or max length
            if (len + 1 > MINLINE) { // print if large enough
                printfromarr(line, len);
            }
            len = 0;
        }
    }
}

/* print first len elements of an arrary */
printfromarr(char line[], int len) {
    int i;
    for(i = 0 ; i < len; ++i) {
        putchar(line[i]);
    }
}