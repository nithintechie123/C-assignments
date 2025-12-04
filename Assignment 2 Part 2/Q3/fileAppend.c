/*
3. Write a C Program that appends one file at the end of the other.
*/

#include <stdio.h>


int main()
{
    FILE *fp1, *fp2; // File pointers for two files
    char ch;         // Variable to store each character read

    // Open first file (source) in read mode
    fp1 = fopen("file1.txt", "r");

    if (fp1 == NULL) // Check if file could not be opened
    {
        printf("Error opening file1.txt\n");
        return 1;
    }

    // Open second file (target) in append mode
    // "a" means new data will be added at the end of the file
    fp2 = fopen("file2.txt", "a");

    if (fp2 == NULL)
    {
        printf("Error opening file2.txt");
        fclose(fp1); // Close already opened file1 before exiting
        return 1;
    }

    // Read content of file1 character by character
    // Continue till EOF (End Of File)
    while ((ch = fgetc(fp1)) != EOF)
    {
        // Write each character to file2
        // Since file2 is opened in append mode, writing starts at the end
        fputc(ch, fp2);
    }

    printf("Contents of file1.txt appended to file2.txt successfully!\n");

    // Close both files to free resources
    fclose(fp1);
    fclose(fp2);
    return 0;
}