#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main (void)
{
        // char *string = malloc(sizeof(char) * 5); // malloc(size_in_bytes)
                                                      // single string: pointer to a char

        int total = 0;

        printf("Enter number of strings: ");
        scanf("%d", &total);

        char **arrString;
        arrString = malloc(total * sizeof(char *)); // malloc(size_in_bytes)

        char buffer[BUFFER_SIZE];
        int length = 0;

        while (getchar() != '\n');

        printf("\n");

        for (int i = 0; i < total; ++i)
        {
                printf("Enter string %d: ", i + 1);
                fgets(buffer, BUFFER_SIZE, stdin);
                length = strlen(buffer);
                buffer[length - 1] = '\0'; // removes the \n char
                arrString[i] = malloc(length * sizeof(char));
                strcpy(arrString[i], buffer);
        }

        printf("\nResulting arrString: \n\n");

        for (size_t i = 0; i < total; ++i)
        {
                printf("arrString[%ld] = %s\n", i, arrString[i]);
        } puts(""); }

