#include <stdio.h>
#include <stdlib.h>

int main (void)
{
        // initialize dynamic array
        int cols = 5;
        int rows = 4;

        int **array = malloc(sizeof(int *) * rows);

        for (int i = 0; i < rows; ++i)
        {
                array[i] = malloc(sizeof(int) * cols);
        }

        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        array[i][j] = (i * 5) + j;
                }
        }

        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        printf("%02d ", array[i][j]);
                }
                printf("\n");
        }

        // increase num of cols

        cols += 5;

        for (int i = 0; i < rows; ++i)
        {
                array[i] = realloc(array[i], sizeof(int) * cols);
        }

        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        array[i][j] = (i * 5) + j;
                }
        }


        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        printf("%02d ", array[i][j]);
                }
                printf("\n");
        }

        puts("");

        // increase num of rows by one

        ++rows;

        array = realloc(array, sizeof(int *) * rows);

        array[rows - 1] = malloc(sizeof(int) * cols); // need to make the new pointer point to a new row of data
                                                      // *we need to allocate a new row of data for the new pointer

        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        array[i][j] = (i * 5) + j;
                }
        }


        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        printf("%02d ", array[i][j]);
                }
                printf("\n");
        }

        puts("");

        // increase num of rows by more than one

        rows += 5;

        array = realloc(array, sizeof(int *) * rows);

        for (int i = rows - 5; i < rows; ++i)
        {
                        array[i] = malloc(sizeof(int) * cols); 
        }


        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        array[i][j] = (i * 5) + j;
                }
        }


        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        printf("%02d ", array[i][j]);
                }
                printf("\n");
        }
        
        // free array

        for (int i = 0; i < rows; ++i)
        {
                free(array[i]);
        }

        free(array);
}
