#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char name[50];
    struct Node *next;
} Node;

Node *createLinkedList(int n){
    Node *temp=NULL,*head=NULL,*newNode=NULL;

    int i;
    char name[50];

    for(i=1;i<=n;i++){
        newNode=(Node*)malloc(sizeof(Node));
        printf("Enter the name of Node %d: ",i);
        scanf("%s",newNode->name);
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
        }else{
            temp->next=newNode;
        }
        temp=newNode;
    }
    return head;
}

Node *deleteName(Node *head,char searchName[]){
    Node *temp=head;
    Node *prev=NULL;

    while(temp!=NULL && strcmp(temp->name,searchName)==0){
        head=temp->next;
        free(temp);
        printf("Name %s deleted successfully.\n",searchName);
        return head;
    }

    while(temp!=NULL && strcmp(temp->name,searchName)!=0){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Name %s not found in the List.\n",searchName);
        return head;
    }

    prev->next=temp->next;
    free(temp);

    printf("Name %s deleted successfully from the List.\n");
    return head;
}

void displayLinkedList(Node *head){

    if(head==NULL){
        printf("List is Empty\n");
        return;
    }

    printf("Linked List Contents:\n");
    while(head!=NULL){
        printf("%s -> ",head->name);
        head=head->next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    Node *head = NULL;
    char searchName[50];

    printf("Enter the number of Nodes:");
    scanf("%d", &n);

    head = createLinkedList(n);
    printf("Original Linked List before Deletion:\n");
    displayLinkedList(head);

    printf("Enter the name to search and delete:");
    scanf("%s", searchName);

    head=deleteName(head,searchName);
    printf("Linked List after Deletion:\n");
    displayLinkedList(head);

    return 0;
}