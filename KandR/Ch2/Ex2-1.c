#include <stdio.h>
#include <limits.h>
#include <float.h>

main() {
    printf("The following info comes from the header files: \n\n");
    printf("Range of `signed char': [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of `unsigned char': [0, %d]\n", UCHAR_MAX);
    printf("Range of `signed short int': [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Range of `unsigned short int': [0, %d]\n", USHRT_MAX);
    printf("Range of `signed int': [%d, %d]\n", INT_MIN, INT_MAX);
    printf("Range of `unsigned int': [0, %u] \n\n\n", UINT_MAX);
}