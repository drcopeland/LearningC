#include <stdio.h>
#include <math.h>

main() {
    int x = -8;
    printf("x: %d\n", x);
    printf("unsigned x: %u\n", (unsigned) x);
    printf("mag(x) + unsigned x: %u\n", -x + (unsigned) x);
}