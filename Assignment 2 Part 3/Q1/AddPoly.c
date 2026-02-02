#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};


int main(){
    struct Node *p1="NULL",*p2="NULL",*sum="NULL";

    //First Polynomial
    insert(&p1,15,3);
    insert(&p1,4,2);
    insert(&p1,2,1);

    //second Polynomial
    insert(&p1,4,3);
    insert(&p1,10,2);
    insert(&p1,20,0);

    printf("Polynomial 1:");
    displayPoly(p1);

    printf("Polynomial 2:");
    displayPoly(p2);

    sum=addPolynomials(p1,p2);

    printf("Sum:");
    display(sum);

    return 0;
}