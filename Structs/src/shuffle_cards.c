#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_TOTAL 52
#define FACES_TOTAL 13

typedef struct card {
        const char *face;
        const char *suit;
} Card;

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main (void)
{
        srand(time(NULL));

        Card deck[DECK_TOTAL];

        const char *face[] = {
                "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
        };

        const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

        fillDeck(deck, face, suit);
        shuffle(deck);
        deal(deck);
}

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]) // why is wDeck not an array here
{
        for (size_t i = 0; i < DECK_TOTAL; ++i)
        {
                wDeck[i].face = wFace[i % FACES_TOTAL]; // i % FACES_TOTAL is so it cycles through the faces
                wDeck[i].suit = wSuit[i / FACES_TOTAL]; // type won't allow for the return of a decimal
                                                        // > will retrun 0, 1, 2, 3  (amazing)
        }
}

void shuffle(Card * const wDeck)
{
        for (size_t i = 0; i < DECK_TOTAL; ++i)
        {
                size_t j = rand() % DECK_TOTAL;
                Card temp = wDeck[i];
                wDeck[i] = wDeck[j];
                wDeck[j] = temp;
        }
}

void deal(const Card * const wDeck)
{
        for (size_t i = 0; i < DECK_TOTAL; ++i)
        {
                printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n"); 
        }
}
