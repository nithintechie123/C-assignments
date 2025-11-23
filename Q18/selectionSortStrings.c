/*
 Write a C program that uses SELECTION sort function to sort a list of STRINGS in
 ascending order.
*/

#include<stdio.h>
#include<string.h>

void selectionSortStrings(char a[][50],int n){
    int i,j,selectedIndex;
    char temp[50];
    for(i=0;i<n;i++){
        selectedIndex=i;
        for(j=i+1;j<n;j++){
            if(strcmp(a[j],a[selectedIndex])<0){
                selectedIndex=j;
            }
        }
        strcpy(temp,a[i]);
        strcpy(a[i],a[selectedIndex]);
        strcpy(a[selectedIndex],temp);
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

    selectionSortStrings(a,n);
    
    printf("Array of strings after using SELECTION sort:\n");
    for(i=0;i<n;i++){
        printf("%s ",a[i]);
    }

}