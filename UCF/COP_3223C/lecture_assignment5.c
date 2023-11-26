#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define SIZE 2
#define TRUE 1
#define FALSE 0



/*Purpose:*/


// creating struct for hand
struct hand {
    int suitsInHand[4];
    int facesInHand[13];
    int straight, flush, four, three, pairs;
};

// declaring functions
void dealHand(struct hand *set);
void analyzeHand(struct hand *set);
void declareHand(struct hand *set);
void announceWinner(struct hand *set);


// main function
int main (void) {
    struct hand *set = (struct hand*) malloc(SIZE * sizeof(struct hand));

    dealHand(set);
    analyzeHand(set);
    declareHand(set);

    /*
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<4;j++) {
            printf("%d", set[i].suitsInHand[j]);
        }
        printf("\n");
        for (int j=0;j<13;j++) {
            printf("%d", set[i].facesInHand[j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i=0;i<SIZE;i++) {
        printf("%d ", set[i].straight);
        printf("%d ", set[i].flush);
        printf("%d ", set[i].four);
        printf("%d ", set[i].three);
        printf("%d ", set[i].pairs);
        printf("\n");
    }
    */
    //announceWinner(set);
}

void dealHand(struct hand *set) {
    char suits[4][10] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    char faces[13][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    srand(time(NULL));
    for (int i=0;i<SIZE;i++) {
        printf("Hand #%d: \n", i+1);
        for (int j=0;j<5;j++) {
            int suitNum = rand() % 4 + 1;
            set[i].suitsInHand[suitNum-1]++;
            int faceNum = rand() % 13 + 1;
            set[i].facesInHand[faceNum-1]++;
            printf("%s of %s\n", suits[suitNum-1], faces[faceNum-1]);
        }
        printf("\n");
    }
}

void analyzeHand(struct hand *set) {
    for (int i=0;i<SIZE;i++) {
        int num_consec = 0;
        int suit, face;

        set[i].straight = FALSE;
        set[i].flush = FALSE;
        set[i].four = FALSE;
        set[i].three = FALSE;
        set[i].pairs = 0;

        // check for flush – 5 cards of the same suit
        for (suit = 0; suit < 4; suit++)
            if (set[i].suitsInHand[suit] == 5)
            set[i].flush = TRUE;

        // check for straight – eg. One each of 5,6,7,8,9
        // locate the first card
        face = 0;
        while (set[i].facesInHand[face] == 0)
            face++;

        // count the consecutive non-zero faces
        for (; face < 13 && set[i].facesInHand[face]; face++)
            num_consec++;

        if (num_consec == 5) {
            set[i].straight = TRUE;
            return;
        }

        // check for 4-of-a-kind, 3-of-a-kind, and pairs
        for (face = 0; face < 13; face++) {
            if (set[i].facesInHand[face] == 4)
                set[i].four = TRUE;
            if (set[i].facesInHand[face] == 3)
                set[i].three = TRUE;
            if (set[i].facesInHand[face] == 2)
                set[i].pairs++;
        }
    }
}

void declareHand(struct hand *set) {
    char hands[4][20] = {"High Card", "Clubs", "Diamonds", "Spades"};
}
