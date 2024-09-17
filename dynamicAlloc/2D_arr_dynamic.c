#include<stdio.h>
#include<stdlib.h>


int main (void)
{

        int staticArr[3][3] =
        {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
        };

        // staticArr[1][2]; // decays to a pointer to 2nd arr,

        /*
        int *arr0 = malloc(sizeof(int) * 3); // each stores a pointer to these blocks of memory 
        int *arr1 = malloc(sizeof(int) * 3);
        int *arr2 = malloc(sizeof(int) * 3);
        */

        // to make a 2D array, we need to make an array of pointers


        /*
        int **arrArr = malloc(sizeof(int *) * 3); // stores 3 int pointers
        arrArr[0] = malloc(sizeof(int) * 3);
        arrArr[1] = malloc(sizeof(int) * 3);
        arrArr[2] = malloc(sizeof(int) * 3);
        */


        size_t rows = 5;
        int cols = 5;

        int **arrArr = malloc(sizeof(int *) * rows); // stores 3 int pointers
                                                  
        for (size_t i = 0; i < rows; ++i)
        {
                arrArr[i] = malloc(sizeof(int) * cols);
        }
        arrArr[1][2] = 5;

        printf("arrArr[1][2]: %d\n", arrArr[1][2]);
        printf("staticArr[1][2]%d\n", staticArr[1][2]);

        for (size_t i = 0; i < rows; ++i)
        {
                free(arrArr[i]);
        }

        free(arrArr);

}
