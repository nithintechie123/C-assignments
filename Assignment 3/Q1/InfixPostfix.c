// 1. Write a C program that uses functions to perform the following:
//  i)converts infix expression into postfix expression using stack.
//  ii)evaluates the postfix expression using 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // For isdigit() and isalnum()
#include <string.h>

#define MAX 100

/* ================= STACK DEFINITION ================= */

/* Stack structure using array */
typedef struct {
    int items[MAX];   // Array to store stack elements (operators or numbers)
    int top;          // Index of top element in stack
} Stack;

/* ================= STACK FUNCTIONS ================= */

/* Initialize stack: make it empty */
void initStack(Stack *s) {
    s->top = -1;   // -1 means stack is empty
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
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;               // Move top up
    s->items[s->top] = value;  // Insert value
}

/* Pop an element from stack */
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = s->items[s->top]; // Take top value
    s->top--;                      // Move top down
    return value;                  // Return popped value
}

/* Peek: return top element without removing it */
int peek(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->items[s->top];
}

/* ================= HELPER FUNCTIONS ================= */

/* Function to return precedence of operators */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;          // Lowest precedence
    if (op == '*' || op == '/')
        return 2;          // Higher precedence
    if (op == '^')
        return 3;          // Highest precedence
    return 0;
}

/* ================= INFIX TO POSTFIX ================= */

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);   // Create and initialize stack

    int i = 0;  // Index for infix
    int k = 0;  // Index for postfix
    char ch;    // Current character

    /* Scan each character of infix expression */
    while (infix[i] != '\0') {
        ch = infix[i];

        /* If operand (letter or digit), add directly to postfix */
        if (isalnum(ch)) {
            postfix[k] = ch;
            k++;
        }
        /* If '(' push it to stack */
        else if (ch == '(') {
            push(&s, ch);
        }
        /* If ')', pop from stack to postfix until '(' is found */
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k] = pop(&s);
                k++;
            }
            pop(&s);  // Remove '(' from stack
        }
        /* If operator (+, -, *, /, etc.) */
        else {
            /* Pop operators from stack with higher or equal precedence */
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k] = pop(&s);
                k++;
            }
            /* Push current operator */
            push(&s, ch);
        }
        i++;  // Move to next character in infix
    }

    /* Pop all remaining operators from stack */
    while (!isEmpty(&s)) {
        postfix[k] = pop(&s);
        k++;
    }

    postfix[k] = '\0';  // End postfix string
}

/* ================= POSTFIX EVALUATION ================= */

int evaluatePostfix(char postfix[]) {
    Stack s;
    initStack(&s);   // Initialize stack for evaluation

    int i = 0;
    char ch;
    int op1, op2, result;

    /* Scan postfix expression */
    while (postfix[i] != '\0') {
        ch = postfix[i];

        /* If operand (digit), push its integer value */
        if (isdigit(ch)) {
            push(&s, ch - '0');  // Convert char '5' to int 5
        }
        /* If operator, pop two operands and apply operator */
        else {
            op2 = pop(&s);   // Second operand
            op1 = pop(&s);   // First operand

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Invalid operator!\n");
                    return 0;
            }

            /* Push result back to stack */
            push(&s, result);
        }
        i++;
    }

    /* Final result will be at top of stack */
    return pop(&s);
}

/* ================= MAIN FUNCTION ================= */

int main() {
    char infix[MAX], postfix[MAX];
    int result;

    printf("Enter infix expression (e.g., 3+5*2): ");
    scanf("%s", infix);

    /* Convert infix to postfix */
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    /* Evaluate postfix expression */
    result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
