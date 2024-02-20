/* Ex. 1-19: Write a function reverse(s) that reverses the
character string s. Use it to write a program that reverses
its input a line at a time. */

#include <stdio.h>

#define MAXLENGTH 1000 // maximum size for a string to reverse

main() {
    char line[MAXLENGTH];
    int c, i;
    
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            line[i] = c;
            ++i;
        }
        else {
            line[i] = '\0';
            reverse(line);
            printf("%s\n", line);
            i = 0;
        }
    }
    
    
}

reverse(char s[]) 
{
    int len, i;
    char si;

    len = strlen(s);
    for(i = 0; i < len - i - 1; ++i) {
        si = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = si;
    }
}

int strlen(char s[])
{
    int len;
    for(len = 0; s[len] != '\0'; ++len) ;
    return len;
}