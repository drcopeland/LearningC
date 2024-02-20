#include <stdio.h>

/* Ex. 2-10: Rewrite the function lower, which converts upper case
characters to lower case, with a conditional expression instaed of if/else. */
main() {
    lower();
}

lower() {
    int c;

    while((c = getchar()) != EOF) {
        (c >= 'A') && (c <= 'Z') ? putchar(c - 'A' + 'a') : putchar(c);
    }
}