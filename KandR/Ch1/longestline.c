/* Ex. 1-16: Revise the main routine of the longest-line program
to correctly print the length of arbitrarily long lines, and as much
as possible of the text. */

#include <stdio.h>
#define MAXLINE 5 /* original max input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
/* K&R version

main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}
*/

main()
{
    int len; // current input length
    int max; // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved so far
    int c, i;

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        
        if (len == MAXLINE - 1 && line[MAXLINE-2] != '\n')  // the line length was > MAXLINE - 1
            for ( ; (c=getchar()) != EOF && c != '\n'; ++len) ; // continue counting the rest of the line
            if (c == '\n')
                ++len;
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) { // there was a line
        printf("Longest line has length %d (including '\\n').\n", max);
        if (max < MAXLINE - 1) 
            for (i = 0; i < max; i++) {
                putchar(longest[i]);
            }
        else
            for (i = 0; i < MAXLINE; i++) {
                putchar(longest[i]);
            }
        putchar('\n');
    }
    return 0;
}

// getline: read a line into s, return length
/*
Behavior:
if len(line) < lim (including \n at the end):
    return len(line) (including \n)
    the first line of input is copied into s, followed by '\0'
if len(line) = lim (including \n at the end):
    return lim - 1
    the first (lim - 1) characters of the line are copied into s, followed by '\0'


*/
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    int i;
    i=0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}