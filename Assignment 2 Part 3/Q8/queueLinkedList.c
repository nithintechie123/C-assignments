//  Write a C Program to perform the following:
//  i) implement a queue ADT using a linked list.
//  ii) display the contents of a list of integers in fifo order using the above queue
//  operations.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("Allocation failed:\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    if (q->front == NULL || q->rear == NULL)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }

    Node *temp = q->front;
    int value=temp->data;

    if(q->front==NULL){
        q->rear=NULL;
    }

    free(temp);
    return value;
}

void display(Queue *q){
    if(q->front==NULL){
        printf("Queue is empty.\n");
    }

    Node *temp=q->front;
    printf("Queue contents (FIFO order): ");

    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Queue q;
    initQueue(&q);
    int i, n, value;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }

    display(&q);

    printf("Dequeued element:%d\n", dequeue(&q));

    display(&q);

    return 0;
}