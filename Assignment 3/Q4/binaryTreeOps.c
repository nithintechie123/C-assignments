// 4. Write C program that uses functions to perform the following:
//  i)create a binary tree of integers.
//  ii)traverse the above binary tree recursively in preorder.
//  iii)traverse the above binary tree recursively in inorder.
//  iv)traverse the above binary tree recursively in postorder.


#include <stdio.h>
#include <stdlib.h>

/* Define structure of a tree node using typedef */
typedef struct Node {
    int data;              // stores the integer data
    struct Node *left;     // pointer to left child
    struct Node *right;    // pointer to right child
} Node;

/* Function to create a binary tree recursively */
Node* createTree() {
    int value;

    printf("Enter node value (-1 for no node): ");
    scanf("%d", &value);

    // If user enters -1, this node is NULL
    if (value == -1) {
        return NULL;
    }

    // Allocate memory for new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    // Recursively create left and right subtrees
    printf("Enter left child of %d\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d\n", value);
    newNode->right = createTree();

    return newNode;
}

/* Preorder Traversal: Root -> Left -> Right */
void preorder(Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);   // Visit root
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

/* Inorder Traversal: Left -> Root -> Right */
void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);         // Traverse left subtree
    printf("%d ", root->data);   // Visit root
    inorder(root->right);        // Traverse right subtree
}

/* Postorder Traversal: Left -> Right -> Root */
void postorder(Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    printf("%d ", root->data);   // Visit root
}

/* Main function */
int main() {
    Node *root = NULL;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
