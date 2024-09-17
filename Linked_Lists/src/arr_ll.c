#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode 
{ 
        char data;
        struct listNode *nextPtr;
} ListNode;

typedef ListNode *ListNodePtr; 

void printLL(ListNode* current);
void RPrintLL(ListNode* current);
void getLenLL(ListNode* current, size_t *len);

int main(void)
{
        size_t lenLL = 0;

        ListNode a;
        ListNode b;
        ListNode c;
        ListNode d;

        ListNode* aPtr = &a;
        ListNode* bPtr = &b;
        ListNode* cPtr = &c;
        ListNode* dPtr = &d;

        aPtr->data = 'A'; 

        bPtr->data = 'B';
        cPtr->data = 'C';
        dPtr->data = 'D';

        aPtr->nextPtr = bPtr;
        bPtr->nextPtr = cPtr;
        cPtr->nextPtr = dPtr;
        dPtr->nextPtr = NULL; // The final element must explicitly be defined as NULL

        printLL(aPtr);
        puts("");

        getLenLL(aPtr, &lenLL);
        printf("%lu", lenLL);
}

void printLL(ListNode* current) // needs to be a pointer as structs are passed by value
{
        while (current != NULL) // if current wasn't a pointer type, this would throw a type error 
        {
                printf("%c", current->data);
                current = current->nextPtr;
        }
}


void getLenLL(ListNode* current, size_t *len) 
{
        while (current != NULL) 
        {
                ++*len;
        }
}

/*
void getLenLL(ListNode* current, size_t *len) 
{
        if (current == NULL) return; // base case
        ++*len;
        getLenLL(current->nextPtr, len); // recursion step
}
*/
