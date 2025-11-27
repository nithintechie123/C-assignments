/*1.
 Define a structure type to represent a complex number. Write a C Program that uses
 functions multcomplex and divcomplex to implement the operations of multiplication
 and division of two complex numbers.
*/

#include <stdio.h> // Includes standard input/output functions like printf and scanf

// ------------------------------------------------------------
// Structure definition for a complex number
// ------------------------------------------------------------
typedef struct
{
    float real; // Stores the real part of the complex number
    float imag; // Stores the imaginary part of the complex number
} Complex;

// ------------------------------------------------------------
// Function to multiply two complex numbers
// Formula: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
// ------------------------------------------------------------
Complex mulComplex(Complex num1, Complex num2)
{
    Complex result; // Structure to store multiplication result

    // Calculate the real part:
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);

    // Calculate the imaginary part:
    result.imag = (num1.real * num2.imag) + (num2.real * num1.imag);

    return result; // Return the final complex result
}

// ------------------------------------------------------------
// Function to divide two complex numbers
// Formula: (a + bi) / (c + di)
// = ( (ac + bd) / (c² + d²) )  +  ( (bc - ad) / (c² + d²) ) i
// ------------------------------------------------------------
Complex divComplex(Complex num1, Complex num2)
{
    Complex result;    // Structure to store division result
    float denominator; // Stores c² + d²

    // Calculate denominator = c² + d²
    denominator = (num2.real * num2.real) + (num2.imag * num2.imag);

    // Calculate real part of the division numerator: (ac + bd)
    // then divide by denominator
    result.real = ((num1.real * num2.real) + (num1.imag * num2.imag)) / denominator;

    // Calculate imaginary part of the division numerator: (bc - ad)
    // then divide by denominator

    result.imag = ((num1.imag * num2.real) - (num1.real * num2.imag)) / denominator;

    return result; // Return final result of division
}

int main()
{
    // Structures to store user-input complex numbers,Multiplication and Division
    Complex num1, num2, mul, div;

    // ----------------- Input first complex number -----------------
    printf("Enter first complex number (real imaginary)\n");
    scanf("%f %f", &num1.real, &num1.imag);

    // ----------------- Input second complex number -----------------
    printf("Enter second complex number (real imaginary)\n");
    scanf("%f %f", &num2.real, &num2.imag);

    // -----Perform multiplication and Division ---------------------
    mul = mulComplex(num1, num2);
    div = divComplex(num1, num2);

    // ----------------- Display results ----------------------------
    printf("Multiplication of two Complex numbers is: ");
    printf("%.2f + %.2fi\n", mul.real, mul.imag);

    printf("Division       of two Complex numbers is: ");
    printf("%.2f + %.2fi\n", div.real, div.imag);

    return 0;
}