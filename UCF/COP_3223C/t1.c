#include <stdio.h>

// mkdir: makes folder
// to make c file: "code file.c"
// to compile: make file
// to run ./file

/*
Programming Rules
    use a header comment to list author, data, purpose
    use comments on every major part
    make variable names meaningful
    use uppercase for constant, i.e. #define

Rules for identifiers i.e. variables
    must be comprissed of letters, didgits and or underscores
    a letter or _ has to be the first characters
    in some instances, casing matters when you name variables
    cannot be a key word like const, define, if, else
    when naming a function, make the name meaningful, printf()

Order of precedence
    *, /, (), and % take precedence, or go left to right if precedence equal

Assignment operators
    increment x=x+1 or x+=1 or x++
    decrement x=x-1 or x-=1 or x--
    multip x*=2
    divid x/=2
        x=x/(p+q); x/=(p+q)

*/

// constant, data type, name, value
const int YARDS_IN_MILE = 1760;

// another way to define constant
#define FEET_IN_YARD 3

int main(void) {
    int feet_in_mile, num_miles;
    feet_in_mile = YARDS_IN_MILE * FEET_IN_YARD;

    printf("How many miles did you run?\n");
    scanf("%d", &num_miles);

    // /: escape sequence, must do // to get actual / in output
    printf("You ran a total of %d feet. \n", feet_in_mile*num_miles);
    return 0;
}