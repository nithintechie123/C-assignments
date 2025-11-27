/*
16. Write a C program that uses insertion sort function to sort a list of integers in
 ascennding order.
*/



#include<stdio.h>

int insertionSort(int a[],int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        temp=a[i];
        for(j=i-1;j>=0 && temp<a[j];j--){
            a[j+1]=a[j];
        }
        a[j+1]=temp;
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

    insertionSort(a,n);

    printf("Sorted elements after using insertion sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

