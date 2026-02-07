// Write a C program that uses functions to perform the following:
//  i)create a binary search tree of integers non recursively.
//  ii)traverse the above binary search tree recursively in inorder.
//  iii)search for an integer key in the above binary search tree non recursively

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node *insertNonRecursive(Node *root,int value){
    Node *newNode=createNode(value);

    if(root==NULL){
        return newNode;
    }

    Node* current=root;
    Node* parent=NULL;

    while(current!=NULL){
        parent=current;

        if(value<current->data){
            current=current->left;
        }else if(value >current->data){
            current=current->right;
        }else{
            printf("Duplicate value %d not inserted.\n",value);
            free(newNode);
            return root;
        }
    }

    if(value<parent->data){
        parent->left=newNode;
    }else{
        parent->right=newNode;
    }

    return root;
}

void inOrderRecursive(Node *root){
    if(root!=NULL){
        inOrderRecursive(root->left);
        printf("%d ",root->data);
        inOrderRecursive(root->right);
    }
}

Node *searchNonRecursive(Node *root,int key){
    Node* current=root;

    while(current!=NULL){
        if(key==current->data){
            return current;
        }else if(key<current->data){
            current=current->left;
        }else{
            current=current->right;
        }
    }
    return NULL;
}

int main(){
    Node* root=NULL;
    int i,n,value,key;
    Node* result;

    printf("Enter the number of nodes to insert: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter value %d: ",i+1);
        scanf("%d",&value);
        root=insertNonRecursive(root,value);
    }

    printf("\nInorder Traversal of BST (sorted order): ");
    inOrderRecursive(root);
    printf("\n");

    printf("\nEnter key to search: ");
    scanf("%d",&key);

    result=searchNonRecursive(root,key);

    if(result!=NULL){
        printf("Key %d FOUND in the BST.\n",key);
    }else{
        printf("Key %d NOT FOUND in the BST.\n",key);
    }
    return 0;
}