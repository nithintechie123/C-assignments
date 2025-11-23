// Write a C program to find the sum of individual digits of a positive integer
#include<stdio.h>
int main(){
    int n,rem,result=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    if(n<0){//negative input check
        printf("Input number can't be negative");
    }else{
        while(n!=0){//loop to extract each digit
            rem=n%10;//extracting last digit
            result=result+rem;//adding digit to result
            n=n/10;//removing last digit from number
        }
        //displaying the result
        printf("Sum of the individual digits of a positive integer:%d",result);
    }
    return 0;
}