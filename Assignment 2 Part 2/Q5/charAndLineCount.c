/*
5. Write a C Program that counts the characters and lines in a text file.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int charCount = 0;
    int lineCount = 0;

    // Check if filename is provided
    if (argc != 2)
    {
        printf("Invalid Arguments");
        return 1;
    }

    // Open the file in read mode
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open the file %s\n", argv[1]);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(fp)) != EOF)
    {
        charCount++; // count every character
        if (ch == '\n')
        {
            lineCount++; // line ends when newline appears
        }
    }

    // Close the file
    fclose(fp);

    if(charCount>0 && ch!='\n'){
        lineCount++;
    }

    // Display the results
    printf("Total Characters: %d\n", charCount);
    printf("Total Lines: %d\n", lineCount);

    return 0;
}
