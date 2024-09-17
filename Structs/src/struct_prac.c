#include<stdio.h>

typedef struct Card
{
        char *face;
        char *suit;
} Card;

int main (void)
{
        Card aCard;

        aCard.face = "Ace";
        aCard.suit = "Spades";

        Card *cardPtr = &aCard; //creates ptr to aCrd of type Card

        printf("%s%s%s\n%s%s%s\n%s%s%s\n", aCard.face, " of ", aCard.suit,
                        cardPtr->face, " of ", cardPtr->suit, // these two 
                        (*cardPtr).face, " of ", (*cardPtr).suit); // are the same
}
