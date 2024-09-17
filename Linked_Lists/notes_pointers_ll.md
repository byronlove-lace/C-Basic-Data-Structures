To print the final element in your linked list, you need to modify your loop condition. Currently, the loop terminates when `current.nextPtr` is `NULL`, which means the loop stops before printing the last element. To include the last element, you can modify the loop condition to check if `current` itself is not `NULL`. Here's the modified code:

```c
void printLinkedList(ListNode* current) {
    while (current != NULL) {
        printf("%c", current->data);
        current = current->nextPtr;
    }
}
```

In this modified code:

- The loop condition `current != NULL` ensures that the loop continues until the `current` pointer itself becomes `NULL`, indicating the end of the linked list.
- `current->data` is used to print the data of the current node.
- `current = current->nextPtr` is used to update `current` to the next node in the linked list.

Make sure that the function `printLinkedList` takes a pointer to the `ListNode` structure (`ListNode* current`), as passing the structure by value (`ListNode current`) would not allow the changes to propagate outside the function.

With this modification, the loop will iterate through all the elements of the linked list, including the final element, and print their data.
