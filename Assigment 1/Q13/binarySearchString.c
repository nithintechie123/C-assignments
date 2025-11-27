/*
13.Write a C program that uses both recursive and non recursive binary search functions
to search for a string
*/

#include <stdio.h>
#include <string.h>

//function for binary search non-recursion method
int binarySearchIterative(char a[][50], int n, char key[])
{
    int lb = 0, ub = n - 1, mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (strcmp(a[mid], key) == 0)
        {
            return mid;
        }
        else if (strcmp(a[mid], key) < 0)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
}

//function for binary search using recursion method
int binarySearchRecursion(char a[][50], int lb, int ub, char key[])
{
    if (lb > ub)
    {
        return -1;
    }

    int mid = (lb + ub) / 2;
    if (strcmp(a[mid], key) == 0)
    {
        return mid;
    }
    else if (strcmp(a[mid], key) < 0)
    {
        return binarySearchRecursion(a, mid + 1, ub, key);
    }
    else
    {
        return binarySearchRecursion(a, lb, mid - 1, key);
    }
}

int main()
{
    int n;
    printf("Enter number of strings in the array:\n");
    scanf("%d", &n);

    char a[n][50];
    printf("Enter the %d strings in to the array:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }

    //
    char key[20];
    printf("Enter the key string:\n");
    scanf("%s", key);

    int choice;
    printf("Select your choice 1 or 2:\n");
    scanf("%d", &choice);

    int resultIterative,resultRecursion;

    //switch case statement for choosing recursive and non-recursive method
    switch (choice)
    {
    case 1:
        resultIterative = binarySearchIterative(a, n, key);
        if (resultIterative == -1)
        {
            printf("Element Not Found.\n");
        }
        else
        {
            printf("Element Found using Iterative search.\n");
        }
        break;
    case 2:
        resultRecursion = binarySearchRecursion(a, 0, n - 1, key);
        if (resultRecursion == -1)
        {
            printf("Element Not Found.\n");
        }
        else
        {
            printf("Element Found using Recursion Method.\n");
        }
        break;
    }
}