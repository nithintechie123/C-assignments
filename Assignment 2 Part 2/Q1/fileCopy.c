/*
1. Write a C Program that copies the contents of one file to another after converting
 all lowercase letters to uppercase?
*/

#include <stdio.h> // Required for file operations like fopen, fgetc, fputc, fclose
#include <ctype.h> // Required for toupper() function that converts lowercase to uppercase

int main()
{
    FILE *source, *target; // File pointers to handle the source and target files
    char ch;               // A variable to store each character read from the source file

    // ---------------------- OPEN SOURCE FILE ----------------------

    // fopen() opens a file. "r" means open in READ MODE.
    // If "input.txt" does not exist or cannot be opened, fopen() returns NULL.

    source = fopen("input.txt", "r");

    // Check whether the source file opened successfully
    if (source == NULL)
    {
        printf("Error:Cannot open input file!\n");
        return 1; // Exit the program with error code 1
    }
    // ---------------------- OPEN TARGET FILE ----------------------

    // fopen() with "w" means OPEN/CREATE the file in WRITE MODE.
    // If "output.txt" does not exist, it will be created.
    // If it exists, its contents will be overwritten.

    target = fopen("output.txt", "w");

    // Check whether the target file opened successfully
    if (target == NULL)
    {
        printf("Error:Cannot open or create output file!\n");
        // Since source was already opened successfully, close it before exiting
        fclose(source);
        return 1; // Exit the program with error code 1
    }

    // ---------------------- CHARACTER-BY-CHARACTER COPY ----------------------

    // Read characters one by one until End-Of-File (EOF) is reached.
    // fgetc() reads a single character from the file and returns EOF when file ends.
    while ((ch = fgetc(source)) != EOF)
    {
        // Convert the character to uppercase.
        // If ch is lowercase (a-z), it becomes uppercase (A-Z).
        // If ch is already uppercase, special symbol, number, or space,
        // toupper() will return it unchanged.
        ch = toupper(ch);
        // Write the character to the target file
        fputc(ch, target);
    }
    // ---------------------- CLOSE BOTH FILES ----------------------

    // Close the source file after reading
    fclose(source);
    fclose(target);
    // Inform the user that the process is complete
    printf("File copied successfully after converting lowercase to uppercase!\n");

    return 0;
}