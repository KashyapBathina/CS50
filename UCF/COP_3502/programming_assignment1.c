#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int freq1[26];
    int freq2[26];
    char* string1 = (char*) malloc(100002 * sizeof(char));
    char* string2 = (char*) malloc(100002 * sizeof(char));

    fgets(string1, 100002, stdin);
    fgets(string2, 100002, stdin);

    printf("%s", string1);
    printf("%s", string2);

    for (int i=0; i<strlen(string1))

    return 0;
}
