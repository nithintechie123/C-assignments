//5. Write a C program to find the factorial of an integer

#include<stdio.h>

int factorial(int n){
    int fact=1,i;
    if(n<0){
        return -1;
    }else{
        for(i=1;i<=n;i++){
            fact*=i;
        }
    }
    
    return fact;
}
int main(){
    int n,result;
    printf("Enter a positive integer:\n");
    scanf("%d",&n);

    result=factorial(n);
    if(result==-1){
        printf("Invalid Input");
    }else{
        printf("Factorial of the %d is :%d",n,result);
    }
    return 0;
}