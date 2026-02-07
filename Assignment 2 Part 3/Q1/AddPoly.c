#include <stdio.h>   // For printf() and scanf()
#include <stdlib.h>  // For malloc() and free()

/*
   Define a structure for a node of the polynomial.
   Each node represents one term of the polynomial:
   coef * x^exp
*/
typedef struct Node {
    int coef;              // Coefficient of the term
    int exp;               // Exponent (power of x)
    struct Node *next;     // Pointer to the next term (node)
} Node;

/*
   Function to create a new node (term) of the polynomial.
   It allocates memory, stores coefficient and exponent,
   and sets next pointer to NULL.
*/
Node* createNode(int coef, int exp) {
    // Allocate memory for one node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Store coefficient in the node
    newNode->coef = coef;

    // Store exponent in the node
    newNode->exp = exp;

    // Since this is a new node, next is set to NULL
    newNode->next = NULL;

    // Return the address of the newly created node
    return newNode;
}

/*
   Function to insert a new term at the end of the linked list.
   head is passed by reference because we may modify it.
*/
void insertEnd(Node **head, int coef, int exp) {
    // Create a new node using the given coefficient and exponent
    Node *newNode = createNode(coef, exp);

    // Temporary pointer to traverse the list
    Node *temp = *head;

    // If the list is empty, make newNode the first node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
}

/*
   Function to create a polynomial linked list by taking input from user.
   The user enters number of terms and then each (coef, exp) pair.
*/
Node* createPolynomial() {
    Node *head = NULL;   // Head pointer of the polynomial list
    int n, i, coef, exp;

    // Ask user for number of terms in the polynomial
    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Loop to read each term
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);

        // Insert each term at the end of the linked list
        insertEnd(&head, coef, exp);
    }

    // Return the head pointer of the created polynomial
    return head;
}

/*
   Function to display a polynomial in proper mathematical form.
   Example: 5x^2 + 3x^1 + 1x^0
*/
void displayPolynomial(Node *head) {
    // If the list is empty, polynomial is 0
    if (head == NULL) {
        printf("0\n");
        return;
    }

    // Traverse the list and print each term
    while (head != NULL) {
        printf("%dx^%d", head->coef, head->exp);

        // Print '+' sign only if it is not the last term
        if (head->next != NULL)
            printf(" + ");

        // Move to the next node
        head = head->next;
    }

    // Print new line after printing polynomial
    printf("\n");
}

/*
   Function to add two polynomials represented using linked lists.
   p1 and p2 are head pointers of the two polynomials.
   The result is stored in a new linked list.
*/
Node* addPolynomials(Node *p1, Node *p2) {
    Node *result = NULL;   // Head pointer for the result polynomial

    // Traverse both polynomials until one becomes NULL
    while (p1 != NULL && p2 != NULL) {

        // If exponents are equal, add the coefficients
        if (p1->exp == p2->exp) {
            int sumCoef = p1->coef + p2->coef;

            // If the sum is not zero, insert it into result list
            if (sumCoef != 0) {
                insertEnd(&result, sumCoef, p1->exp);
            }

            // Move both pointers forward
            p1 = p1->next;
            p2 = p2->next;
        }
        // If exponent of first polynomial is greater,
        // copy that term into result
        else if (p1->exp > p2->exp) {
            insertEnd(&result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        // If exponent of second polynomial is greater,
        // copy that term into result
        else {
            insertEnd(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    // If there are remaining terms in first polynomial, copy them
    while (p1 != NULL) {
        insertEnd(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    // If there are remaining terms in second polynomial, copy them
    while (p2 != NULL) {
        insertEnd(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    // Return the head pointer of the result polynomial
    return result;
}

/*
   Main function: Execution starts from here
*/
int main() {
    Node *poly1 = NULL;   // Head pointer for first polynomial
    Node *poly2 = NULL;   // Head pointer for second polynomial
    Node *sum = NULL;     // Head pointer for sum polynomial

    // Create first polynomial
    printf("Create first polynomial:\n");
    poly1 = createPolynomial();

    // Create second polynomial
    printf("\nCreate second polynomial:\n");
    poly2 = createPolynomial();

    // Display both polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    sum = addPolynomials(poly1, poly2);

    // Display the result
    printf("\nSum of Polynomials: ");
    displayPolynomial(sum);

    return 0;   // End of program
}
