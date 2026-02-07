// 10. Write a C program to merge two sorted arrays of integers to produce a third sorted
//  array contai


#include <stdio.h>

/*
   Program to merge two sorted arrays into a third sorted array
   in ascending order.
*/

int main() {
    int n1, n2;                 // Sizes of the two arrays
    int i = 0, j = 0, k = 0;     // Index variables

    // Read size of first array
    printf("Enter number of elements in first sorted array: ");
    scanf("%d", &n1);

    int a[n1];  // First array

    // Read elements of first array (must be in sorted order)
    printf("Enter %d elements in ascending order:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second array
    printf("Enter number of elements in second sorted array: ");
    scanf("%d", &n2);

    int b[n2];  // Second array

    // Read elements of second array (must be in sorted order)
    printf("Enter %d elements in ascending order:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Third array size is sum of first two arrays
    int c[n1 + n2];   // Merged array

    i = 0;  // Index for array a
    j = 0;  // Index for array b
    k = 0;  // Index for array c

    /*
       Merge process:
       Compare elements of a[] and b[] and
       store the smaller one into c[]
    */
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            c[k] = a[i];   // Copy element from a[]
            i++;           // Move index of a[]
        } else {
            c[k] = b[j];   // Copy element from b[]
            j++;           // Move index of b[]
        }
        k++;               // Move index of c[]
    }

    /*
       If any elements are left in array a[],
       copy them directly into c[]
    */
    while (i < n1) {
        c[k] = a[i];
        i++;
        k++;
    }

    /*
       If any elements are left in array b[],
       copy them directly into c[]
    */
    while (j < n2) {
        c[k] = b[j];
        j++;
        k++;
    }

    // Display the merged sorted array
    printf("\nMerged Sorted Array:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
