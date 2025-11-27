/*
6. Declare an array of 30 student structures where each structure contains the fields,
 name, idno and marks. Write a C Program that sorts the above array of students
 structures on the name field using insertion sort.
*/

#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[50];
    int id_no;
    float marks;
} Student;

int main()
{
    int n, i, j,selectedIndex;
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

    Student temp;

    //Insertion Sort Algorithm to sort students by name
    for (i = 1; i < n; i++)
    {
       temp=s[i];//Store the current student in temp
       for(j=i-1;j>=0 && strcmp(s[j].name,temp.name)>0;j--){//Compare names using strcmp
        s[j+1]=s[j];//Shift student to the right
       }
       s[j+1]=temp;//Insert temp at the correct position
    }

    printf("\n--- Students Sorted by name (Insertion Sort) ---\n");
    printf("Name\t\tIdNo\t\t Marks\t\t\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%.2f\t\t\n", s[i].name, s[i].id_no, s[i].marks);
    }

    return 0;
}