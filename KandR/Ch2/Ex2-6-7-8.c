
#include <stdio.h>
#include <math.h>

main() {
    int x =  -12;
    int n = 3;
    int result;
    printf("  x: %3d, bits: ", x);
    printbits(x);
    printf("\n");
    printf(" x << 1: %3d, bits: ", x << 1);
    printbits(x << 1);
    printf("\n");
    printf(" x >> 1: %3d, bits: ", x >> 1);
    printbits(x >> 1);
    
    printf("\n");
    
}
/* Ex. 2-6: Write a function setbits(x,p,n,y) that returns x
with the n bits that begin at position p set to the rightmost n bits of y,
leaving the other bits unchanged. */


/* We assume "positions" are indexed starting at 0, starting from the right
(as in binary or decimal representation of numbers). The function assumes p >= n. */
int setbits(int x, int p, int n, int y) {
    int masky;
    int maskx;

    maskx = ~(~0 << p + 1) & ((x >> (p - n + 1)) << (p-n + 1)); // x with all but the bits to replace = 0
    masky = (y & ~(~0 << n)) << (p + 1 - n); // the rightmost n bits of y, moved to position p
    return (x ^ masky) ^ maskx;
    
}

/* Ex. 2-7: Write a function invert(x,p,n) that returns x with 
the n bits that begin at position p inverted, leaving the rest unchanged. */

// We assume p >= n, and as usual bit positions are counted from the right.
int invert(int x, int p, int n) {
    int mask;
    mask = ~((~0 << p + 1) ^ ~(~0 << p + 1 - n)); // 0's except in the n bits starting at p
    return x ^ mask;
}

/* Ex 2-8. Write a function rightrot(x, n) that returns
the value of the integer x rotated to the right by n bit positions. 
*/
int rightrot(int x, int n) {
    if (n == 0) {
        return x;
    }
    else {
        return (x >> n) ^ (x << (32 - n));
    }
}


/* turn an int into bits, assuming ints are 32-bit */
void printbits(int x) {
    char bits[32];
    int i;

    if (x < 0) {
        bits[0] = '1';
        x = ((int) pow(2,31)) + x + 1;
    }
    else {
        bits[0] = '0';
    }
    

    for (i = 1; i < 32; i++) {
        int powof2;
        powof2 = (int) pow(2, (32 - i - 1));
        if (x >= powof2) {
            bits[i] = '1';
            x = x - powof2;
        }
        else {
            bits[i] = '0';
        }
    }

    
    printf("%.32s", bits);
}


