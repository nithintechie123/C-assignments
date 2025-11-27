/*
2. Declare an array of 30 student structures where each structure contains the fields,
 name, idno and marks. Write a C Program that sorts the above array of students
 structures on the name field using bubble sort
*/

#include <stdio.h>
#include <string.h>

typedef struct //Student structure definition
{
    char name[50];
    int id_no;
    float marks;
} Student;

int main()
{
    Student s[30];//Array of student structures
    int i, j, n;//n is number of students

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


    //Input student details
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

    Student temp;//Temporary variable for swapping

    //Bubble Sort Algorithm to sort students by name
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(s[j].name, s[j + 1].name) > 0)//Compare names for sorting using strcmp
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    //Output sorted list of students
    printf("\n--- Students Sorted by Name (Bubble Sort) ---\n");
    printf("Name\t IdNo\t Marks\t\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t  %d\t  %.2f\t\n", s[i].name, s[i].id_no, s[i].marks);
    }

    return 0;
}