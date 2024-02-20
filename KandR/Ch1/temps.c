#include <stdio.h>

/* print Farenheit -> Celsius conversion table
    for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define UPPER 300
#define STEP 20

main () {
    int fahr;
    
    printf("Celsius to Farenheit conversion table.\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

}