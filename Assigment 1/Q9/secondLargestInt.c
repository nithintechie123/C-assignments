/*9. Write a C program to find the second largest integer in a list of integers.*/

#include<stdio.h>

int main(){
    int n,a[10],i,j,temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the %d elements into the array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    printf("---------------------\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n---------------------\n");
    
    int largest=a[0],secondLargest;
    secondLargest=-1;
    for(i=1;i<n;i++){
        if(a[i]<largest){
            secondLargest=a[i];
            break;
        }
    }

    if(secondLargest==-1){
        printf("No second largest element (all elements are equal).\n");
    }else{
        printf("Second largest element: %d\n", secondLargest);
    }

    
    
}