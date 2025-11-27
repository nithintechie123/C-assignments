/*
3. Declare an array of 30 student structures where each structure contains the fields,
 name, idno and marks. Write a C Program that sorts the above array of students
 structures on the marks field using bubble sort
*/

#include <stdio.h>

typedef struct
{
    char name[50];
    int id_no;
    float marks;
} Student;

int main()
{
    int n, i, j;
    Student s[30];

    //Input number of students and their details
    printf("Enter the number of students (max 30): ");
    if (scanf("%d", &n) != 1) {                // validate input
        printf("Invalid input. Exiting.\n");
        return 1;
    }
    if (n < 1 || n > 30) {                     // bounds check
        printf("Number of students must be between 1 and 30. Exiting.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the details of student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("idNo: ");
        scanf("%d", &s[i].id_no);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    Student temp;

    //Bubble Sort Algorithm to sort students by marks
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].marks > s[j + 1].marks)//Compare marks for sorting
            {
                temp = s[j];//Swap students
                s[j] = s[j + 1];//Swap students
                s[j + 1] = temp;//Complete the swap
            }
        }
    }

    printf("\n--- Students Sorted by Marks (Bubble Sort) ---\n");
    printf("Name\t\tIdNo\t\t Marks\t\t\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%.2f\t\t\n", s[i].name, s[i].id_no, s[i].marks);
    }

    return 0;
}