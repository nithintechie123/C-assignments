// Write a C Program to perform the following:
//  i) implement a stack ADT using an array.
//  ii) display the contents of a list of integers in reverse order using the above stack
//  operations

// #include <stdio.h>

// #define MAX 100   // Maximum size of the stack

// /*-------------------------------------------------
//  Step 1: Define Stack structure using typedef
// --------------------------------------------------*/
// typedef struct {
//     int arr[MAX];   // Array to store stack elements
//     int top;        // Variable to store index of top element
// } Stack;

// /*-------------------------------------------------
//  Step 2: Function to initialize the stack
// --------------------------------------------------*/
// void initStack(Stack *s) {
//     s->top = -1;    // Stack is empty when top = -1
// }

// /*-------------------------------------------------
//  Step 3: Function to push an element into stack
// --------------------------------------------------*/
// void push(Stack *s, int value) {

//     // Check for Stack Overflow
//     if (s->top == MAX - 1) {
//         printf("Stack Overflow! Cannot push %d\n", value);
//         return;
//     }

//     // Increment top and insert value
//     s->top++;
//     s->arr[s->top] = value;
// }

// /*-------------------------------------------------
//  Step 4: Function to pop an element from stack
// --------------------------------------------------*/
// int pop(Stack *s) {

//     // Check for Stack Underflow
//     if (s->top == -1) {
//         printf("Stack Underflow! Stack is empty\n");
//         return -1;
//     }

//     // Return top element and decrease top
//     return s->arr[s->top--];
// }

// /*-------------------------------------------------
//  Step 5: Main Function
// --------------------------------------------------*/
// int main() {

//     Stack s;        // Declare stack variable
//     int n, i, value;

//     // Initialize the stack
//     initStack(&s);

//     // Read number of elements
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     // Read and push elements into stack
//     printf("Enter %d elements:\n", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &value);
//         push(&s, value);   // Push element into stack
//     }

//     // Pop and display elements (reverse order)
//     printf("\nElements in reverse order:\n");
//     while (s.top != -1) {
//         printf("%d ", pop(&s));
//     }

//     return 0;   // End of program
// }

#include <stdio.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow! cannot push %d into stack\n", value);
        return;
    }

    s->top++;
    s->arr[s->top] = value;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow! Stack is empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

void printOriginalOrder(Stack *s){
    int i;
    for(i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
} 

int main()
{
    Stack s;
    int i, n, value;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    initStack(&s);

    printf("Enter the %d elements in stack:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&s, value);
    }

    printf("\nElements in original order:\n");
    printOriginalOrder(&s);

    printf("\nElements in reverse order:\n");
    while (s.top != -1)
    {
        printf("%d ", pop(&s));
    }
    return 0;
}