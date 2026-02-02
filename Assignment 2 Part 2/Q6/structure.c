/*
6. Write a C Program that performs the following:
 i)writes 10 student structures to a binary file f1, where each structure contains the
 fields, idno and marks.
 ii)reads the nth student structure from the file f1 and displays it to standard output
 device.
*/


#include <stdio.h>
#include <stdlib.h>

/* Define a structure for student details */
typedef struct {
    int idno;
    float marks;
} Student;

int main(void) {
    const char *filename = "f1.bin";
    FILE *fp;
    Student s;
    int i;

    /* ------------------ PART (i) WRITE 10 STRUCTURES ------------------ */

    /* Open file in binary write mode ("wb") */
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    printf("Enter details for 10 students (idno marks):\n");

    /* Loop to input and write 10 student records */
    for (i = 0; i < 10; ++i) {
        printf("Student %d: ", i + 1);

        /* Read idno and marks from user */
        if (scanf("%d %f", &s.idno, &s.marks) != 2) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            fclose(fp);
            return 1;
        }

        /* Write one student structure to binary file */
        if (fwrite(&s, sizeof(Student), 1, fp) != 1) {
            perror("Error writing to file");
            fclose(fp);
            return 1;
        }
    }

    /* Close the file after writing */
    fclose(fp);
    printf("Successfully wrote 10 records to '%s'.\n", filename);

    /* ------------------ PART (ii) READ THE Nth STRUCTURE ------------------ */

    int n;
    printf("Enter the record number to read (n) [1..10]: ");

    /* Read the value of n from user */
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input. Exiting.\n");
        return 1;
    }

    /* Validate n */
    if (n < 1 || n > 10) {
        fprintf(stderr, "n must be between 1 and 10.\n");
        return 1;
    }

    /* Open file again in binary read mode ("rb") */
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    /* Calculate byte position of the (n-1)th structure */
    long offset = (long)(n - 1) * sizeof(Student);

    /*
        Move file pointer to the required position.
        SEEK_SET → beginning of file.
        offset = number of bytes from start of file.
    */
    if (fseek(fp, offset, SEEK_SET) != 0) {
        perror("fseek failed");
        fclose(fp);
        return 1;
    }

    /* Read one structure from the calculated position */
    if (fread(&s, sizeof(Student), 1, fp) != 1) {
        if (feof(fp))
            fprintf(stderr, "Unexpected end of file.\n");
        else
            perror("fread failed");
        fclose(fp);
        return 1;
    }

    /* Display the nth student record */
    printf("\nRecord %d:\n", n);
    printf("ID No : %d\n", s.idno);
    printf("Marks : %.2f\n", s.marks);

    /* Close the file */
    fclose(fp);
    return 0;
}
