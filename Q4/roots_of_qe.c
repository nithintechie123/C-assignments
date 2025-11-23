// 4. Write a C program to find the roots of a quadratic equation.
#include <stdio.h>
#include <math.h> //for sqrt() function
int main()
{
    float a, b, c, root1, root2, discriminant, realPart, imaginaryPart; // declare variables
    printf("Enter the coefficients of a,b and c:");                     // a,b and c are coefficients of the quadratic equation
    scanf("%f %f %f", &a, &b, &c);  
    printf("---------------------\n");                                    // input coefficients

    discriminant = b * b - 4 * a * c; // calculate discriminant

    if (discriminant > 0) // if discriminant is positive, roots are real and different
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct(different).\n");
        printf("Root1=%.2f and Root2=%.2f", root1, root2);
    }
    else if (discriminant == 0)
    { // if discriminant is zero, roots are real and equal
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal\n");
        printf("Root1 = Root2 = %.2f\n", root1);
    }
    else
    { // if discriminant is negative, roots are complex and imaginary
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and imaginary.\n");
        printf("Root1 = %.2f+%.2f i and Root2 = %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
    }
    return 0;
}