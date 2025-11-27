/*
10.Write a C program that uses both recursive and non recursive linear search functions
 to search for an integer key value in a list of integers
*/
#include <stdio.h>

int main()
{
    int key, a[10], i, n, flag = 0;
    printf("Enter the number of elements to be entered in the array:");
    scanf("%d", &n);

    printf("Enter the %d elements into the array:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the key element:");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Element found");
    }
    else
    {
        printf("Element Not Found");
    }
    return 0;
}
