/*
5. Declare an array of 30 student structures where each structure contains the fields,
 name, idno and marks. Write a C Program that sorts the above array of students
 structures on the name field using selection sor
*/

#include <stdio.h>
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

    //Selection Sort Algorithm to sort students by name
    for (i = 0; i < n; i++)
    {
       selectedIndex=i;//Assume the current index is the minimum
       for(j=i+1;j<n;j++){//Check the rest of the array
        if(strcmp(s[j].name,s[selectedIndex].name)<0){//Compare names using strcmp  
            selectedIndex=j;//Update selectedIndex if a smaller name is found
        }
       }
       temp=s[i];//Swap the found minimum element with the first element
       s[i]=s[selectedIndex];//Place the smallest name at the current position
       s[selectedIndex]=temp;//Complete the swap
    }

    printf("\n--- Students Sorted by name (Selection Sort) ---\n");
    printf("Name\t\tIdNo\t\t Marks\t\t\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%.2f\t\t\n", s[i].name, s[i].id_no, s[i].marks);
    }

    return 0;
}