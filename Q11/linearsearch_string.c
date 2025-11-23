/*11.Write a C program that uses both recursive and non recursive linear search functions
 to search for a string*/

#include <stdio.h>
#include <string.h>

// linear search for string in an array of strings using non-recursive method
int linearsearch(char a[][50], char key[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}

// linear search for a string in an array of strings using recursive method
int linearrecursivesearch(char a[][50], char key[], int n, int index)
{
    if (index >= n)//if index of array is out of range return -1
    {
        return -1;
    }

    if (strcmp(a[index], key) == 0)//if key element matches with string in the array return index value
    {
        return index;
    }
    return linearrecursivesearch(a, key, n, index + 1);
}
int main()
{
    int n, choice;
    printf("Enter the number of elements to be entered in the array:\n");
    scanf("%d", &n);

    char a[n][50];//two-dimensional array which stores array of strings
    char key[50];//key string

    printf("Enter the %d strings:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);//input of array of strings
    }

    printf("Enter key string to search: ");
    scanf("%s", key);//input of key string
    printf("Enter your choice 1 or 2:");
    scanf("%d", &choice);

    printf("\n-------Result--------\n");

    int result1, result2;

    switch (choice)
    {
    case 1:
        result1 = linearsearch(a, key, n);
        if (result1 == -1)
        {
            printf("Key Element not found in the array of strings\n\n");
        }
        else
        {
            printf("Key Element found in the array of strings\n");
        }
        break;
    case 2:
        result2 = linearrecursivesearch(a, key, n, 0);
        if (result2 == -1)
        {
            printf("Key Element not found in the array of strings\n");
        }
        else
        {
            printf("Key Element found in the array of strings\n");
        }
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}