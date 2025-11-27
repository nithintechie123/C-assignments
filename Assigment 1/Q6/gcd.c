/*Write a C program that uses recursive and non recursive functions to find the GCD
 (greatest common divisor) of two integers. Develop a menu driven program?
*/

#include <stdio.h>
int gcd_non_recursive(int a,int b);//function prototype for non-recursive gcd

int gcd_recursive(int a,int b);//function prototype for recursive gcd

int main(){
    int num1,num2,choice,result;//variable declaration
    printf("Enter the numbers num1 and num2:\n");
    scanf("%d %d",&num1,&num2);
    printf("Menu:\n");
    printf("1.Enter choice 1 for non-recursive function\n");
    printf("2.Enter choice 2 for recursive function\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch (choice)//menu driven switch case
    {
    case 1:
        result=gcd_non_recursive(num1,num2);//function call for non-recursive gcd
        printf("Gcd of %d and %d using non-recursive function is:%d",num1,num2,result);
        break;
    case 2:
        result=gcd_recursive(num1,num2);//function call for recursive gcd
        printf("Gcd of %d and %d using recursive function is:%d",num1,num2,result);
        break;
    default:
        printf("Invalid Input");
        break;
    }
    return 0;
}

int gcd_non_recursive(int a,int b){
    int temp;//temporary variable
    while(b!=0){//loop until b becomes 0
        temp=b;//store b in temp
        b= a % b;//update b to a mod b
        a=temp;//update a to temp
    }
    return a;//return a as gcd
}

int gcd_recursive(int a,int b){
    if(b==0){//base case
        return a;//return a as gcd
    }
    return gcd_recursive(b,a%b);//recursive call with updated values
}