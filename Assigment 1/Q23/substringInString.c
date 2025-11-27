/*
23. Write a C program that displays the position or index in the string S where the string
 T begins, or – 1 if S doesn’t contain T.
*/

#include <stdio.h>
#include <string.h>

int main() {

    // Declare main string S and substring T
    char S[100], T[50];

    int i, j;          // loop variables
    int found;         // flag to check if substring matched
    int index = -1;    // result index, -1 means NOT found

    // -------------------- INPUT STRING S --------------------
    printf("Enter string S: ");
    fgets(S, sizeof(S), stdin);        // read full line including newline

    S[strcspn(S, "\n")] = '\0';        // remove newline (replace '\n' with '\0')

    // -------------------- INPUT STRING T --------------------
    printf("Enter string T: ");
    fgets(T, sizeof(T), stdin);        // reads substring including newline

    T[strcspn(T, "\n")] = '\0';        // remove newline

    // Lengths of both strings
    int lenS = strlen(S);
    int lenT = strlen(T);

    // -------------------- SEARCH SUBSTRING --------------------
    // Loop S from 0 to (lenS - lenT)
    for (i = 0; i <= lenS - lenT; i++) {

        found = 1;   // assume substring matches at index i

        // Compare each character of T with S starting at i
        for (j = 0; j < lenT; j++) {

            // If any character mismatches → not a match
            if (S[i + j] != T[j]) {
                found = 0;
                break;
            }
        }

        // If substring fully matched
        if (found == 1) {
            index = i;      // store index
            break;          // stop after first match
        }
    }

    // -------------------- OUTPUT RESULT --------------------
    if (index == -1)
        printf("-1\n");     // substring NOT found
    else
        printf("String T begins at index: %d\n", index);

    return 0;
}
