// 2. Write a C program that uses functions to perform the following:
//  i)create a binary search tree of integers recursively.
//  ii)traverse the above binary search tree recursively in inorder.
//  iii)search for an integer key in the above binary search tree recursively.


#include <stdio.h>
#include <stdlib.h>

/* ========== Definition of BST Node ========== */
typedef struct Node {
    int data;              // Stores integer data
    struct Node *left;     // Pointer to left child
    struct Node *right;    // Pointer to right child
} Node;

/* ========== Function Prototypes ========== */
Node* createNode(int value);
Node* insert(Node* root, int value);     // Create BST recursively
void inorder(Node* root);                // Inorder traversal recursively
Node* search(Node* root, int key);        // Search key recursively

/* ========== Create a new node ========== */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory
    newNode->data = value;     // Set data
    newNode->left = NULL;      // Initialize left child
    newNode->right = NULL;     // Initialize right child
    return newNode;            // Return new node
}

/* ========== Insert into BST (Recursively) ========== */
Node* insert(Node* root, int value) {
    /* If tree (or subtree) is empty, create a new node */
    if (root == NULL) {
        return createNode(value);
    }

    /* If value is less than root data, insert in left subtree */
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    /* If value is greater than root data, insert in right subtree */
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    /* If value is equal, we do nothing (no duplicates) */

    return root;  // Return unchanged root pointer
}

/* ========== Inorder Traversal (Left, Root, Right) ========== */
void inorder(Node* root) {
    /* If tree is not empty */
    if (root != NULL) {
        inorder(root->left);          // Visit left subtree
        printf("%d ", root->data);    // Visit root
        inorder(root->right);         // Visit right subtree
    }
}

/* ========== Search in BST (Recursively) ========== */
Node* search(Node* root, int key) {
    /* If tree is empty or key is found at root */
    if (root == NULL || root->data == key) {
        return root;   // Return NULL (not found) or node address (found)
    }

    /* If key is smaller than root data, search left subtree */
    if (key < root->data) {
        return search(root->left, key);
    }
    /* Else, search right subtree */
    else {
        return search(root->right, key);
    }
}

/* ========== Main Function ========== */
int main() {
    Node* root = NULL;   // Initially, BST is empty
    int n, i, value, key;
    Node* result;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    /* Insert elements into BST */
    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);   // Insert recursively
    }

    /* Display inorder traversal */
    printf("\nInorder traversal of BST (sorted order): ");
    inorder(root);
    printf("\n");

    /* Search for a key */
    printf("\nEnter key to search: ");
    scanf("%d", &key);

    result = search(root, key);

    if (result != NULL) {
        printf("Key %d FOUND in the BST.\n", key);
    } else {
        printf("Key %d NOT FOUND in the BST.\n", key);
    }

    return 0;
}
