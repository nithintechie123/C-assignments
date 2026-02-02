/*
24. Write a C program to count the lines, words and characters in a given text.
*/
#include <stdio.h>

int main() {
    char text[1000];
    int lines = 0, words = 0, chars = 0;
    int i;

    printf("Enter the text (end input with ENTER twice):\n");

    while (fgets(text, sizeof(text), stdin)) {
        // If user enters an empty line, stop
        if (text[0] == '\n')
            break;

        lines++; // Count each non-empty line

        // Count characters and words in the line
        for (i = 0; text[i] != '\0'; i++) {
            chars++;

            // Word counting logic
            if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
                words++;
            }
        }

        // Last word in the line (if line not empty)
        if (i > 1)  
            words++;
    }

    printf("\n--- Result ---\n");
    printf("Lines      : %d\n", lines);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", chars);

    return 0;
}
