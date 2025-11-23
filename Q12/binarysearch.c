/*
Write a C program that uses both recursive and non recursive binary search functions
to search for an integer key value in a sorted (ascending order) list of integers.
*/

#include<stdio.h>

int binarySearchIterative(int a[],int n,int key){
    int lb=0,ub=n-1;
    while(lb<=ub){
        int mid=(lb+ub)/2;
        if(a[mid]==key){
            return mid;
        }else if (a[mid]>key){
            ub=mid-1;
        }else{
            lb=mid+1;
        }
    }
    return -1;
}

int binarySearchRecursive(int a[],int lb,int ub,int key){
    if(lb>ub){
        return -1;
    }

    int mid = (lb+ub)/2;
    if(a[mid]==key){
        return mid;
    }else if(a[mid]>key){
        return binarySearchRecursive(a,lb,mid-1,key);
    }else{
        return binarySearchRecursive(a,mid+1,ub,key);
    }
    
}

int main(){
    int n,mid,lb,ub,key,flag=0;
    printf("Enter the number of elements to be entered in the array:\n");
    scanf("%d",&n);

    int a[n];
    printf("Enter the %d elements into the array:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the key elements:\n");
    scanf("%d",&key);

    int resultIter=binarySearchIterative(a,n,key);

    if(resultIter!=-1){
        printf("Element found at index %d\n",resultIter);
    }else{
        printf("Element not found\n");
    }

    int resultRec=binarySearchRecursive(a,0,n-1,key);
    if(resultRec!=-1){
        printf("Element found at index %d\n",resultRec);
    }else{
        printf("Element not found\n");
    }

    return 0;
}