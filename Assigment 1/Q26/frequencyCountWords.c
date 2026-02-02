/*26.	Write a C Program that makes frequency count of all the words in a given text. 
*/

#include <stdio.h>
#include <string.h>

int main() {
    char text[500];
    char words[100][50];
    int freq[100] = {0};
    int wordCount = 0;

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    // Split text into words (space-separated)
    char *w = strtok(text, " ");

    while (w != NULL) {

        // Remove newline from last word
        w[strcspn(w, "\n")] = '\0';

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], w) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If word not found, add to list
        if (!found) {
            strcpy(words[wordCount], w);
            freq[wordCount] = 1;
            wordCount++;
        }

        w = strtok(NULL, " ");
    }

    // Print the frequency count
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s : %d\n", words[i], freq[i]);
    }

    return 0;
}
