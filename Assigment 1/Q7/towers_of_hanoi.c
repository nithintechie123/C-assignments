#include <stdio.h>

// Recursive function to solve Towers of Hanoi
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Step 1: Move top n-1 disks to auxiliary peg
    hanoi(n - 1, from, aux, to);

    // Step 2: Move largest disk
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Step 3: Move n-1 disks from auxiliary to target
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSolution:\n");
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
