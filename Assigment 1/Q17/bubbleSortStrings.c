/*
 Write a C program that uses BUBBLE sort function to sort a list of STRINGS in
 ascending order.
*/

#include<stdio.h>
#include<string.h>

void bubbleSortString(char a[][50],int n){
    int i,j;
    char temp[50];
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(a[j],a[j+1])>0){
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
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

    bubbleSortString(a,n);

    printf("Array of strings after using BUBBLE sort\n");
    for(i=0;i<n;i++){
        printf("%s ",a[i]);
    }

}