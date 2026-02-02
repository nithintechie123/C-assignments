#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

struct Node *insert(struct Node *head, int coef, int exp)
{
    struct Node *temp;
    struct Node *newP = malloc(sizeof(struct Node));
    newP->coef = coef;
    newP->exp = exp;
    newP->next = NULL;

    if (head == NULL || exp > head->exp)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp >= exp)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

struct Node *create(struct Node *head)
{
    int i, n;
    int coef;
    int exp;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d:", i + 1);
        scanf("%d", &coef);

        printf("Enter the exponent of term %d:", i + 1);
        scanf("%d", &exp);

        head = insert(head, coef, exp);
    }
    return head;
}

void print(struct Node* head)
{
    if (head == NULL)
    {
        printf("No Polynomial..");
    }else{
        struct Node* temp=head;
        while(temp!=NULL){
            printf("%dx^%d",temp->coef,temp->exp);
            temp=temp->next;
            if(temp!=NULL){
                printf("+");
            }else{
                printf("\n");
            }
        }
    }
}

int main()
{
    struct Node *head = NULL;
    printf("Enter the polynomial:\n");
    head = create(head);
    print(head);
    return 0;
}