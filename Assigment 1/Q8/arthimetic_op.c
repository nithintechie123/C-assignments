/*Write a C program, which takes two integer operands and one operator from the user,
 performs the operation and then prints the result. (Consider the operators +,-,*, /, %
 and use Switch
*/

#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter two numbers a and b:\n");
    scanf("%d %d", &a, &b);
    printf("Enter the choice for operation:\n");
    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Modulus\n");
    int choice;
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("%d + %d = %d", a, b, a + b);
        break;
    case 2:
        printf("%d - %d = %d", a, b, a - b);
        break;
    case 3:
        printf("%d * %d = %d", a, b, a * b);
        break;
    case 4:
        printf("%d / %d = %d", a, b, a / b);
        break;
    case 5:
        printf("%d %% %d = %d", a, b, a % b);
        break;
    default:
        break;
    }
}