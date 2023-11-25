#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define SIZE 2



/*
    name: Kashyap Bathina
    date: 11/6/23
    purpose: This programs takes in three integers and passes them through
    a function which returns the largest of the three using if statements.
    Then returns that number to main and prints it.
*/



// creating struct for hand
struct hand {
    int suitsInHand[4];
    int facesInHand[13];
};

// declaring functions
void dealHand(struct hand *set);
void analyzeHand(int a, int b, int c);
void declareHand(int a, int b, int c);


// main function
int main (void) {
    struct hand *set = (struct hand*) malloc(SIZE * sizeof(struct hand));

    for (int i=0;i<SIZE;i++) {
        dealHand(set);
    }

}

void dealHand(struct hand *set) {
    char suits[4][10] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    char faces[13][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    srand(time(NULL));
    for (int i=0;i<SIZE;i++) {
        //set[i] = (struct hand) {.suitsInHand = {0}, .facesInHand = {0}};
        printf("Hand #%d: \n", i+1);
        for (int j=0;j<5;j++) {
            int suitNum = rand() % 4 + 1;
            set[i].suitsInHand[suitNum-1]++;
            int faceNum = rand() % 13 + 1;
            set[i].facesInHand[faceNum-1]++;
            printf("%s of %s\n", suits[suitNum-1], faces[faceNum-1]);
        }

        for (int k=0;k<4;k++) {
            printf("%d", set[k].suitsInHand[k]);
        }
        printf("\n");
        for (int k=0;k<13;k++) {
            printf("%d", set[k].facesInHand[k]);
        }


        printf("\n");
    }
}
