#include <stdio.h>

/* Ex. 2-9: In a 2's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Then write a faster version of bitcount. */

/* REASONING: 
Case 1: x > 0

Then in bits we can write x = *100...0, with zero or more 0's appearing. Then
x - 1 = *011..1 (with zero or more 1's appearing, resp.). In either case,
x & (x-1) = *000..0, i.e. x with the rightmost 1-bit deleted.

Case 2: x = 0
Then in bits x & (any int) = 0000...0 (as desired).

Case 3: INT_MIN < x < 0 [doesn't work?]
Then we can write x = 1*100...0 as before. This time, x-1 = 1*100...1.

*/

main () {
    int x = 10213;
    printf("KR bitcount: %d\n", KRbitcount(x));
    printf("My bitcount: %d\n", mybitcount(x));
}

int KRbitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01)
            b++;
    }
    return b;
}

int mybitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}