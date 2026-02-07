//  i) create a linked list of integers.
//  ii) reverse the links in the above list, traverse and display its contents.


#include <stdio.h>
#include <stdlib.h>

/*
   Create an alias for struct Node using typedef
*/
typedef struct Node
{
    int data;          // Stores data of the node
    struct Node *next; // Stores address of next node
} Node;

/*
   Function to create a single node
*/
Node *createNode(int value)
{

    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory
    newNode->data = value;                        // Assign value
    newNode->next = NULL;                         // Next is NULL initially

    return newNode;
}

/*
   Function to create a linked list dynamically
*/
Node *createLinkedList(int n)
{

    Node *head = NULL;    // Head of the list
    Node *temp = NULL;    // Temporary pointer
    Node *newNode = NULL; // New node
    int value, i;

    for (i = 1; i <= n; i++)
    {

        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        // Create new node
        newNode = createNode(value);

        // If list is empty, first node becomes head
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        // Otherwise, attach node at the end
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head; // Return head of the list
}

/*
   Function to reverse the linked list
*/
Node *reverseList(Node *head)
{
    Node *prev = NULL; // Previous node
    Node *curr = head; // Current node
    Node *next = NULL; // Next node

    while (curr != NULL)
    {

        next = curr->next; // Save next node
        curr->next = prev; // Reverse the link
        prev = curr;       // Move prev forward
        curr = next;       // Move curr forward
    }

    return prev; // New head
}

/*
   Function to display the linked list
*/
void printList(Node *head)
{

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/*
   Main function
*/
int main()
{

    Node *head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    head = createLinkedList(n);

    printf("\nOriginal Linked List:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}
