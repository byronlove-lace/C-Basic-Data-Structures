#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main (void)
{
        // single string
        int length = 6; // needs to be 6 to include nunll terminator
        char *singleString = malloc(sizeof(char) * length);
        strcpy(singleString, "hello"); // need to use strcpy here
                                       // assignment with string literal is not possible with dynamicArrs
        printf("%s\n", singleString);
        free(singleString);

        // array of strings

        char **arrString;
        int total = 0;
        char buffer[BUFFER_SIZE];
        size_t buffLen = 0;   

        printf("Enter number of strings: ");
        scanf("%d", &total);
        arrString = malloc(sizeof(char *) * total); // don't forget sizeof
        while (getchar() != '\n'); // flushes stdin


        for (size_t i = 0; i < total; ++i)
        {
                printf("\nEnter String %ld:", i + 1);


                fgets(buffer, BUFFER_SIZE, stdin); // fgets WILL store \n in the buffer and append \0

                buffLen = strlen(buffer);

                buffer[buffLen - 1] = '\0'; // we replace the \n with \0

                arrString[i] = malloc(sizeof(char) * buffLen); // typically might need buffLen + 1 to account for \0
                                                               // but since we've moved it back in the above code
                                                               // we don't need to here 

                strcpy(arrString[i], buffer); // copy from buffer to dynamicArr
        }

        printf("\n Resulting Strings Array: \n\n");

        for (size_t i = 0; i < total; ++i)
        {
                printf("arrString[%ld]: %s\n", i, arrString[i]);
        }
}

