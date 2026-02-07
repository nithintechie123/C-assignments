// 6. Write a C Program to convert a given infix expression into postfix form using stack?

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // For isalnum()
#include <string.h>

#define MAX 100

/* ========== Stack Structure ========== */
typedef struct {
    char items[MAX];   // Array to store stack elements (operators)
    int top;           // Index of top element
} Stack;

/* ========== Stack Functions ========== */

/* Initialize stack */
void initStack(Stack *s) {
    s->top = -1;   // Stack is empty when top = -1
}

/* Check if stack is empty */
int isEmpty(Stack *s) {
    return s->top == -1;
}

/* Check if stack is full */
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

/* Push an element onto stack */
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = value;  // Increment top and insert value
}

/* Pop an element from stack */
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[s->top--];   // Return top and decrement top
}

/* Peek top element without removing */
char peek(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->items[s->top];
}

/* ========== Function to Return Precedence ========== */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;      // Lowest precedence
    if (op == '*' || op == '/')
        return 2;      // Higher precedence
    if (op == '^')
        return 3;      // Highest precedence
    return 0;
}

/* ========== Function to Convert Infix to Postfix ========== */
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);   // Initialize stack

    int i = 0;  // Index for infix
    int k = 0;  // Index for postfix
    char ch;    // Current character

    /* Scan each character of infix expression */
    while (infix[i] != '\0') {
        ch = infix[i];

        /* If operand (letter or digit), add to postfix */
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        /* If '(', push it to stack */
        else if (ch == '(') {
            push(&s, ch);
        }
        /* If ')', pop from stack to postfix until '(' is found */
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Remove '(' from stack
        }
        /* If operator */
        else {
            /* Pop operators from stack with higher or equal precedence */
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            /* Push current operator to stack */
            push(&s, ch);
        }
        i++;  // Move to next character in infix
    }

    /* Pop all remaining operators from stack */
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';  // End postfix string
}

/* ========== Main Function ========== */
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (e.g., A+B*C): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
