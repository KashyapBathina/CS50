#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("W: ");
    char *t = &s;

    printf("%p\n", s);
    printf("%p\n", t);
}