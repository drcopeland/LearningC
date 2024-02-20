#include <stdio.h>

/* Ex. 2-4: Write an alternate version of squeeze(s_1, s_2) that deletes
each character in s1 that matches any character in the string s_2. */

main () {
    char s1[] = "Hello, world.";
    char s2[] = "I am Alex.";

    squeeze(s1, s2);

    printf(s1);
    printf("\n");
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    k = 0;

    for (i=0; s1[i] != '\0'; ++i) {
        for (j = 0; (s2[j] != s1[i]) && (s2[j] != '\0'); ++j) ;
        if (s2[j] == '\0') { // the character s1[i] was not found in s2
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}