#include <stdio.h>
#include <cs50.h>

void number(void);

int main(void)

{
    int answer = get_int("How tall is the pyramid?  ");
    printf("Height = %i\n", answer);
}
