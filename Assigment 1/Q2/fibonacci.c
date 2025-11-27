/*Fibonacci sequence is defined as follows:
 the first and second terms in the sequence are 0 and 1.
 Subsequent terms are found by adding the preceding two terms in the sequence. 
 Write a C program to generate the first n terms of the sequence*/

#include<stdio.h>
int main(){
    int i,n,first=0,second=1,next;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    
    if(n<0){//negative input check
        printf("Input can't be negative");
    }else{//for non-negative input
        printf("Below are the %d terms of fibonacci series\n",n);
        printf("%d %d ",first,second);//printing first two terms
        for(i=0;i<n-2;i++){//loop to generate remaining terms
            next=first+second;//calculating next term
            first=second;//updating first term
            second=next;//updating second term
            printf("%d ",next);//printing next term
        }
    }
    return 0;
}