// 5. Write a C Program to perform the following:
//  i) implement a queue ADT using an array.
//  ii) display the contents of a list of integers in fifo order using the above queue
//  operation


#include <stdio.h>

#define MAX 100   // Maximum size of the queue

/*========================================================
  STEP 1: Define Queue ADT using structure
========================================================*/
typedef struct {
    int arr[MAX];   // Array to store queue elements
    int front;      // Index of the first element
    int rear;       // Index of the last element
} Queue;

/*========================================================
  STEP 2: Initialize the Queue
========================================================*/
void initQueue(Queue *q) {
    q->front = -1;  // Queue is empty initially
    q->rear  = -1;
}

/*========================================================
  STEP 3: Enqueue Operation (Insert element at REAR)
========================================================*/
void enqueue(Queue *q, int value) {

    /* Check for Queue Overflow
       If rear reaches last index, no space is left */
    if (q->rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;     // Stop insertion
    }

    /* If queue is empty, initialize front */
    if (q->front == -1) {
        q->front = 0;
    }

    /* Move rear forward and insert element */
    q->rear++;
    q->arr[q->rear] = value;
}

/*========================================================
  STEP 4: Dequeue Operation (Remove element from FRONT)
========================================================*/
int dequeue(Queue *q) {

    /* Check for Queue Underflow
       Queue is empty if front is invalid */
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }

    /* Return front element and move front forward */
    return q->arr[q->front++];
}

/*========================================================
  STEP 5: Display Queue Elements in FIFO Order
========================================================*/
void displayQueue(Queue *q) {
    int i;

    /* Check if queue is empty */
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }

    /* Display elements from front to rear */
    printf("Queue elements in FIFO order: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

/*========================================================
  STEP 6: Main Function
========================================================*/
int main() {

    Queue q;            // Declare queue variable
    int n, i, value;

    /* Initialize the queue */
    initQueue(&q);

    /* Read number of elements */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Read elements and insert into queue */
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    /* Display elements in FIFO order */
    displayQueue(&q);

    return 0;   // Program ends
}
