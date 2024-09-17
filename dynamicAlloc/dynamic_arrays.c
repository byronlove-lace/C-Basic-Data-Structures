#include <stdio.h>
#include <stdlib.h>

int *arr;

size_t ARR_SIZE = 256;

int main(void)
{
        arr = calloc(ARR_SIZE, sizeof(int)); // calloc(numofelems, sizeof(elem)) 
                                             // we use calloc here instead of malloc 
                                             // cuz calloc sets all mem to 0 (good for arrays) 
        if (arr == NULL)
                fprintf(stderr, "Arrat not allocated!"); // printf but we can determine the output stream

        arr[10] = 69;
        printf("%d\n", arr[10]);

        ARR_SIZE *= 2;
        arr = realloc(arr, ARR_SIZE * sizeof(int)); // array = realloc(array, newsize(in bytes)) 
        if (arr == NULL)
                fprintf(stderr, "Arrat not allocated!"); 

        free(arr);

}
