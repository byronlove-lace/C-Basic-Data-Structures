#include <stdio.h>
#include <string.h>

#define LEN 9

void bubbleSort(char stringArr[][100], size_t arrLen, size_t elemLen);

int main (void)
{
        char reindeer[LEN][100] = 
        {
                "Prancer",
                "Cupid",
                "Dasher",
                "Doner",
                "Blitzen",
                "Vixen",
                "Dancer",
                "Rudolph",
                "Comet",
        };

        bubbleSort(reindeer, LEN, 100);

        for (size_t i = 0; i < LEN; ++i)
        {
                printf("%s\n", reindeer[i]);
        }

}

void bubbleSort(char stringArr[][100], size_t arrLen, size_t elemLen)
{
        char temp[elemLen];

        for (size_t i = 0; i < arrLen; ++i)
        {
                for (size_t j = 0; j < (arrLen - 1); ++j)
                {
                        if (strcmp(stringArr[j], stringArr[j + 1]) > 0) // if string[j] > string[j + 1] 
                        {
                                strcpy(temp, stringArr[j]);
                                strcpy(stringArr[j], stringArr[j + 1]);
                                strcpy(stringArr[j + 1], temp);
                        }
                }
        }
}
