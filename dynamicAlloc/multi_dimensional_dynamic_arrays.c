#include<stdio.h>

int main (void)
{

        int **arr = malloc(sizeof(int*) * 3);
        for (size_t i = 0; i < 3; ++i)
        {
                arr[i] = malloc(sizeof(int) * 3);
        }
        arr[0];
        arr[2][0];

}
