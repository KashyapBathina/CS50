#include <stdio.h>

// Program 1
int main(void) {
    // declaring variables, the sum, and the average
    long int var1, var2, var3, var4, var5;
    long int sum;
    double average;

    // reading in first input
    scanf("%ld", &var1);
    printf("You entered: %ld\n", var1);

    scanf("%ld", &var2);
    printf("You entered: %ld\n", var2);

    scanf("%ld", &var3);
    printf("You entered: %ld\n", var3);

    scanf("%ld", &var4);
    printf("You entered: %ld\n", var4);

    scanf("%ld", &var5);
    printf("You entered: %ld\n", var5);

    sum = var1 + var2 + var3 + var4 + var5;
    average = sum/5;

    printf("The sum of the numbers you entered is: %ld\n", sum);
    printf("The average is: %f\n", average);
}