#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string text = get_string("Text: ");

    // letters
    while (text != "\n" )
    int Letters = strlen(text);
    printf("%i letters\n", Letters);

    // sentences
    int Sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.')
        Sentences ++;
    }
    printf("%i sentences\n", Sentences);
}