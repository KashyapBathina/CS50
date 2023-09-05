#include <stdio.h>

/*
    Implicit Casting (automatically) - converting a smaller type to a larger type size. char -> int -> long -> float -> double.
    Explicit Casting (manually) - converting a larger type to a smaller size type. double -> float -> long -> int -> char.
*/

int main(void) {
    int grade1 = 75;
    int grade2 = 80;

    int average1 = (grade1+grade2)/2;
    int average2 = grade1+grade2/2;
    int average3 = grade2+grade1/2;
    double average4 = (grade1+grade2)/2;
    double average5 = (double)(grade1+grade2)/2;
    double average6 = (grade1+grade2)/2.0;
    double average7 = (double)((grade1+grade2)/2);
    int average8 = (grade1+grade2/2.0);

    //&d=placeholder
    printf("Avg #1 = %d\n", average1);
    printf("Avg #2 = %d\n", average2);
    printf("Avg #3 = %d\n", average3);
    printf("Avg #4 = %d\n", average4);
    printf("Avg #5 = %d\n", average5);
    printf("Avg #6 = %d\n", average6);
    printf("Avg #7 = %d\n", average7);
    printf("Avg #8 = %d\n", average8);

}