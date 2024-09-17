#include<stdio.h>
#include<stdlib.h>

int main(void)
{
        int* p = (int*) malloc(3 * sizeof(int));
        // malloc allows for memory allocation on the heap 
        // it returns a pointer to the start of that address
        // It takes the size of the amount of memory desired in bites
        // To avoid warnings, we cast the return to the desired type
        // * Memory is only truly allocated when we start to use it!
        
        *p = 5;
        p[1] = 10;
        p[2] = 15;

        printf("%d\n", *p);
        printf("%d\n", p[1]);
        printf("%d\n", p[2]);

        free(p);
}
