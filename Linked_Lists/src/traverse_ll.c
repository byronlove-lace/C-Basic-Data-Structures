#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode
{
        char data;
        struct listNode *nextPtr;
} ListNode;

typedef ListNode *ListNodePtr; 

void printLL(ListNode* current) // needs to be a pointer as structs are passed by value
{
        while (current != NULL) // if current wasn't a pointer type, this would throw a type error 
        {
                printf("%c", current->data);
                current = current->nextPtr;
        }
}

void RPrintLL(ListNode* current) 
{
        if (current == NULL) return; // base case
        printf("%c", current->data);
        RPrintLL(current->nextPtr); // recursion step
}

int main(void)
{
       ListNode a;
       ListNode b;
       ListNode c;
       ListNode d;

       ListNode* aPtr = &a;
       ListNode* bPtr = &b;
       ListNode* cPtr = &c;
       ListNode* dPtr = &d;

       aPtr->data = 'A'; // same as (*aPtr).data
                         // allows for manipulation in funcs
       bPtr->data = 'B';
       cPtr->data = 'C';
       dPtr->data = 'D';

       aPtr->nextPtr = bPtr;
       bPtr->nextPtr = cPtr;
       cPtr->nextPtr = dPtr;

       // a -> b -> c -> d -> NULL
       printLL(aPtr);
       puts("");

       // a -> b -> c -> d -> NULL
       //               cur->
       //                      cur is NULL: return
       RPrintLL(aPtr);
       puts("");
}
