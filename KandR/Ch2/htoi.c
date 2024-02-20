#include <stdio.h>
#include <string.h>

/* Ex. 2-3: Write the function htoi(s), which converts a string of decimal digits 
(including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F. */

main () {
    int x = htoi("02ef49");
    printf("%d\n", x);
    printf("%x\n", x);
}

int htoi(char s[]) {
    int i, n, val;
    int p1, p2;
    n = 0;
    if (strlen(s) > 1 && s[1] == 'x') {
        i = 2;
    }
    else {
        i = 0;
    }

    for (; (p1 = (s[i] >= '0' && s[i] <= '9')) 
        || (p2 = (s[i] >= 'A' && s[i] <= 'F')) 
        || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
        if (p1) {
            val = s[i] - '0';
        }
        else if (p2) {
            val = 10 + s[i] - 'A';
        }
        else {
            val = 10 + s[i] - 'a';
        }
        n = 16 * n + val;
    }
    
    return n;
}