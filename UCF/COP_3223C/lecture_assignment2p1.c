#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
    name: Kashyap Bathina
    date: 9/3/23
    purpose: Lorem Ipsum Dolor
*/

int main() {
    //
    int years, months, weeks, days, hours;
    double now;
    #define leap_years_since_1970 13

    //
    now = time(NULL);

    //
    int sec_in_hours = 60*60;
    int sec_in_days = sec_in_hours * 24;
    int sec_in_weeks = sec_in_days * 7;
    int sec_in_months = sec_in_days * 30.42;
    int sec_in_years = sec_in_days * 365;

    printf("%d\n", sec_in_hours);
    printf("%d\n", sec_in_days);
    printf("%d\n", sec_in_weeks);
    printf("%d\n", sec_in_months);
    printf("%d\n", sec_in_years);



    return 0;
}