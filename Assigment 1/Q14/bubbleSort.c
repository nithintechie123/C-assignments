/*
Write a C program that uses functions to perform the following:
 i)sort a list of integers in ascending order bubble sort.
 ii)search for an integer key non recursively in the above sorted list using binary
 search
*/

#include<stdio.h>

//bubble sort function
void bubbleSort(int a[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}

//binary search function on sorted array  using non-recursive method
int binarySearchNonRecur(int a[],int n,int key){
    int lb=0,ub=n-1,mid;

    while(lb<=ub){
        mid=(lb+ub)/2;
        if(a[mid]==key){
            return mid;
        }else if (a[mid]<key){
            lb=mid+1;
        }else{
            ub=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);

    int a[n];

    printf("Enter the %d elements to be entered into the array:",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int result;

    bubbleSort(a,n);


    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    int key;
    printf("\nEnter the key element:");
    scanf("%d",&key);

    int resultNonRecur;

    resultNonRecur=binarySearchNonRecur(a,n,key);

    if(resultNonRecur==-1){
        printf("Element Not Found.\n");
    }else{
        printf("Element Found at index %d Using Non-Recursion Method",resultNonRecur);
    }

    return 0;
}