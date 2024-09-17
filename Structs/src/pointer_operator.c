#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
        int x;
        int y;

} Point;

int main (void)
{
        Point p1;

        p1.x = 3;
        p1.y = 2;

        printf("p1: %d %d\n", p1.x, p1.y);

        Point *p2;
        p2 = &p1;

        p2->x = 5;
        p2->y = 4;
        // gives us access to the member variables of a struct that this pointer is pointing to
        printf("p2: %d %d\n", p2->x, p2->y);

        Point *p3;
        p3 = malloc(sizeof(Point));
        // returns mem address for block large enough to store a point
        p3->x = 15;
        p3->y = 55;

        printf("p3: %d %d\n", p3->x, p3->y);
        // no need for complicated notation (*p3).x

        (*p3).x = 6;

}

