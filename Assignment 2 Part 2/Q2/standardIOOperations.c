/*2.Write a C program that uses the standard I/O package (library functions) to count
 the number of times a given character occurs in a file. It takes the filename and
 the character as command-line arguments.
*/

#include <stdio.h>  // For standard I/O functions: printf, fopen, fgetc, fclose
#include <stdlib.h> // For exit(), general utilities

int main(int argc, char *argv[])
{
    FILE *fp;      // File pointer to handle the file
    int count = 0; // To store each character read from file
    char ch;       // Character whose occurrences we want to count
    char target;   // Counter for occurrences

    /******************** ARGUMENT VALIDATION ********************/
    // The program expects exactly 3 arguments:
    // 1. Program name
    // 2. File name
    // 3. Character to search
    if (argc != 3)
    {
        printf("Error: Invalid arguments!\n");
        printf("Usage: %s <filename> <character>\n", argv[0]);
        return 1; // Return 1 indicates an ERROR / abnormal termination
    }

    /******************** READING CHARACTER ARGUMENT ********************/
    // argv[2] is a string (example: "a"), so we take the first character
    target = argv[2][0];

    /******************** OPEN THE FILE ********************/
    // Try to open the file in READ mode
    fp = fopen(argv[1], "r");

    // If fopen fails, it returns NULL → meaning file not found / unreadable
    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1; // return error
    }

    /******************** COUNTING OCCURRENCES ********************/
    // Read file character-by-character until end-of-file (EOF)

    while ((ch = fgetc(fp)) != EOF)
    {
        // If the character matches the target, increment count
        if (ch == target)
        {
            count++;
        }
    }

    /******************** CLOSE FILE ********************/
    // Closing file is very important:
    // 1. Frees memory buffers
    // 2. Releases file resources
    // 3. Prevents file corruption
    fclose(fp);

    printf("Character '%c' occurs %d times in the file %s\n", target, count, argv[1]);

    return 0; // normal termination
}