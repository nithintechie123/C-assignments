// 9. Write a C program to merge two sorted singly linked lists of integers to produce a
//  third sorted singly linked list containing the elements of both the sorted lists in
//  ascending order

#include <stdio.h>
#include <stdlib.h>

/* 
   Define a structure for a node of singly linked list.
   Each node contains:
   1) data  -> integer value
   2) next  -> pointer to the next node
*/
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* 
   Function to create a linked list with n nodes.
   It takes input from user and returns the head pointer.
*/
Node* createList(int n) {
    Node *head = NULL;   // Will store address of first node
    Node *temp = NULL;   // Used to traverse and attach new nodes
    Node *newNode = NULL;// Used to create a new node
    int value;           // To store user input

    for (int i = 1; i <= n; i++) {
        // Allocate memory for new node
        newNode = (Node*)malloc(sizeof(Node));

        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        // Store data and set next as NULL
        newNode->data = value;
        newNode->next = NULL;

        // If this is the first node, make it head
        if (head == NULL) {
            head = newNode;
            temp = head;
        } 
        // Otherwise, attach new node at the end
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;  // Return the head of the list
}

/* 
   Function to display the elements of a linked list
*/
void display(Node *head) {
    Node *temp = head;   // Start from head

    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print data
        temp = temp->next;            // Move to next node
    }
    printf("NULL\n");
}

/* 
   Function to merge two sorted linked lists into one sorted list.
   l1 and l2 are heads of the two sorted lists.
   It returns head of the merged sorted list.
*/
Node* mergeSortedLists(Node *l1, Node *l2) {
    Node *mergedHead = NULL; // Head of merged list
    Node *mergedTail = NULL; // Tail pointer to build the list

    // If first list is empty, return second list
    if (l1 == NULL) return l2;

    // If second list is empty, return first list
    if (l2 == NULL) return l1;

    /* 
       Step 1: Initialize mergedHead with smaller first element
       Compare first nodes of both lists
    */
    if (l1->data <= l2->data) {
        mergedHead = l1;     // l1 node is smaller
        l1 = l1->next;       // Move l1 to next node
    } else {
        mergedHead = l2;     // l2 node is smaller
        l2 = l2->next;       // Move l2 to next node
    }

    // Set mergedTail to the first node of merged list
    mergedTail = mergedHead;

    /* 
       Step 2: Compare remaining nodes of both lists
       and keep adding the smaller one to merged list
    */
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            mergedTail->next = l1;  // Attach l1 node
            l1 = l1->next;          // Move l1 ahead
        } else {
            mergedTail->next = l2;  // Attach l2 node
            l2 = l2->next;          // Move l2 ahead
        }
        mergedTail = mergedTail->next; // Move tail forward
    }

    /* 
       Step 3: If any list still has remaining nodes,
       attach them directly because they are already sorted
    */
    if (l1 != NULL) {
        mergedTail->next = l1;
    } else {
        mergedTail->next = l2;
    }

    // Return head of the merged sorted list
    return mergedHead;
}

/* Main function */
int main() {
    Node *list1 = NULL;      // Head of first list
    Node *list2 = NULL;      // Head of second list
    Node *mergedList = NULL; // Head of merged list
    int n1, n2;

    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements in ascending order:\n");
    list1 = createList(n1);

    printf("\nEnter number of nodes in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements in ascending order:\n");
    list2 = createList(n2);

    printf("\nFirst Sorted List: ");
    display(list1);

    printf("Second Sorted List: ");
    display(list2);

    // Merge the two sorted lists
    mergedList = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted List: ");
    display(mergedList);

    return 0;
}
