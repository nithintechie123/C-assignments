/*
25.	Write a C Program that makes frequency count of all the letters in a given text.
*/

#include <stdio.h>
#include <ctype.h>   // for tolower()

int main() {
    char text[1000];
    int freq[26] = {0};   // frequency for a to z
    int i;

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    // Count frequencies
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Convert to lowercase
        ch = tolower(ch);

        // Check if it's a letter
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    // Print results
    printf("\nLetter Frequency:\n");
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", (char)(i + 'a'), freq[i]);
        }
    }

    return 0;
}
