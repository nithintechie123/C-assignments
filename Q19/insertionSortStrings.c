/*
 Write a C program that uses INSERTION sort function to sort a list of STRINGS in
 ascending order.
*/


#include<stdio.h>
#include<string.h>

void insertionSortStrings(char a[][50],int n){
    int i,j;
    char temp[50];
    for(i=1;i<n;i++){
        strcpy(temp,a[i]);
        for(j=i-1;j>=0 && strcmp(a[j],temp)>0;j--){
            strcpy(a[j+1],a[j]);
        }
        strcpy(a[j+1],temp);
    }
}

int main(){
    int n,i;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    char a[n][50];
    printf("Enter the %d strings into the array:",n);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }

    insertionSortStrings(a,n);
    
    printf("Array of strings after using INSERTION sort:\n");
    for(i=0;i<n;i++){
        printf("%s ",a[i]);
    }

}