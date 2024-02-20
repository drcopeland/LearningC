/* Ex. 2-6: Write a function setbits(x,p,n,y) that returns x
with the n bits that begin at position p set to the rightmost n bits of y,
leaving the other bits unchanged. */

#include <stdio.h>

main() {
    int i;
    for (i=0; i < 10; ++i) {
        printf("%d: %d\n", i, setbits(i,3,2,3));
    }
}
/* We assume "positions" are indexed starting at 0, starting from the right
(as in binary or decimal representation of numbers). The function assumes p >= n. */
int setbits(int x, int p, int n, int y) {
    return (x & (y << n));
}