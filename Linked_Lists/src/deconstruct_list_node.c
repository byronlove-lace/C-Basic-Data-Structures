#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode
{
        char data;
        struct listNode *nextPtr;
} ListNode;

typedef ListNode *ListNodePtr; //?

void insert(ListNodePtr *sPtr, char value);

int main(void)
{
        ListNodePtr startPtr = NULL; // no initial nodes
        char item = 'a'; // char entered by user
        insert(&startPtr, item); // insert item in list 
}

void insert(ListNodePtr * sPtr, char value)
{
        ListNodePtr newPtr = malloc(sizeof(ListNode)); // dynamically alloc at runtime
                                                       // we're creating a pointer to struct at runtime 

        if (newPtr != NULL) // check if space is available 
        {
                newPtr->data = value; // place value in node
                newPtr->nextPtr = NULL; // node does not link to anothre node

                ListNodePtr previousPtr = NULL;
                ListNodePtr currentPtr = *sPtr;

                // loop to find the correct location in the list
                while (currentPtr != NULL && value > currentPtr->data)
                {
                        previousPtr = currentPtr; // walk to
                        currentPtr = currentPtr->nextPtr; // next node
                }

                if (previousPtr == NULL)
                {
                        newPtr->nextPtr = *sPtr;
                        *sPtr = newPtr;
                }
                else 
                { // insert new mode between previousPtr and currentPtr
                        previousPtr->nextPtr = newPtr;
                        newPtr->nextPtr = currentPtr;
                }
        }
        else
        {
                printf("%c not inserted. No memory available.\n", value);
        }
}
