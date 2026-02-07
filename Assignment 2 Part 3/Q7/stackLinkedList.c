// 7. Write a C Program to perform the following:
//  i) implement a stack ADT using a linked list.
//  ii) display the contents of a list of integers in reverse order using the above stack
 

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *top=NULL;

void push(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));

    if(newNode==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data=value;
    newNode->next=top;
    top=newNode;
}

int pop(){
    if(top==NULL){
        printf("Stack Underflow!\n");
        return -1;
    }

    Node *temp=top;
    int poppedValue=temp->data;

    top=top->next;
    free(temp);
    return poppedValue;
}

void displayStack(){
    Node *temp=top;

    printf("Stack (top to bottom):\n");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int i,n,value;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter the %d elements:\n",n);
    for(i=0;i<n;i++){
        printf("Enter the value at position %d:",i+1);
        scanf("%d",&value);
        push(value);
    }

    printf("Original List Entered:\n");
    displayStack();

     printf("Now displaying in reverse order using stack:\n");

     while(top!=NULL){
        printf("%d ",pop());
     }
     printf("\n");
     return 0;
}