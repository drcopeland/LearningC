#include <stdio.h>
#include <time.h>


/* Ex. 3-1: KR's binary search makes two tests inside the loop, when one would
suffice (at the price of more tests outside). Write a version with just one test
inside the loop and measure the difference in runtime. */

main() {
    int n = 1000000000;
    static int v[1000000000];
    int x = 4;
    int KRresult, myresult;

    clock_t begin = clock();
    KRresult = binsearch(x, v, n);
    clock_t end = clock();
    double KRtime_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("KR binsearch: %d. Time: %f\n", binsearch(x, v, n), KRtime_spent);

    begin = clock();
    myresult = mybinsearch(x, v, n);
    end = clock();
    double mytime_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("My binsearch: %d. Time: %f\n", mybinsearch(x, v, n), mytime_spent);
    
}
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else { /*found match */ 
            return mid;
        }
    }
    return -1; // no match
}

int mybinsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    mid = (low + high) / 2;

    while ((low <= high) && (v[mid] != x)) {
        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high)/2;
    }
    if (v[mid] == x) {
        return mid;
    }
    else {
        return -1;
    }

}