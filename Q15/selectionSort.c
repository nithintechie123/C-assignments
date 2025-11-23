/*
15. Write a C program that uses functions to perform the following:
 i)sort a list of integers in ascending order selection sort.
 ii)search for an integer key recursively in the above sorted list using binary search.
*/

#include <stdio.h>

void selectionSort(int a[],int n){
    int selectedIndex,temp,i,j;
    for(i=0;i<n;i++){
        selectedIndex=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[selectedIndex]){
                selectedIndex=j;
            }
        }
        temp=a[i];
        a[i]=a[selectedIndex];
        a[selectedIndex]=temp;
    }
}

int binarySearchRecursive(int a[],int key,int lb,int ub){
    if(lb>ub){
        return -1;
    }

    int mid=(lb+ub)/2;

    if(a[mid]==key){
        return mid;
    }else if(a[mid]<key){
        return binarySearchRecursive(a,key,mid+1,ub);
    }else{
        return binarySearchRecursive(a,key,lb,mid-1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int a[n];

    printf("Enter the %d elements to be entered into the array:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    selectionSort(a,n);

    //sorted elements after using selection sort

    printf("Sorted elements after using selection sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    int key;
    printf("\nEnter the key value: ");
    scanf("%d",&key);

    int result;
    result=binarySearchRecursive(a,key,0,n-1);

    if(result==-1){
        printf("\nElement Not Found\n");
    }else{
        printf("Element Found at index %d using Recursive Binary Search Method",result);  
    }
    return 0;
}