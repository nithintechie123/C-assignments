#include <stdio.h>
#include <string.h>

int main() {
    char bin[100];
    int len, i;
    int foundOne = 0;

    printf("Enter a binary number: ");
    scanf("%s", bin);

    len = strlen(bin);

    // Traverse from right to left
    for (i = len - 1; i >= 0; i--) {
        if (foundOne == 0) {
            // Copy until first 1 is found
            if (bin[i] == '1') {
                foundOne = 1;
            }
        } else {
            // Complement bits after the first 1
            bin[i] = (bin[i] == '0') ? '1' : '0';
        }
    }

    printf("2's complement = %s\n", bin);
    return 0;
}