/*
22. Write a C program that uses recursive and nonrecursive functions to determine if
 the given string is a palindrome or not. A palindrome is a message that reads the
 same both forwards and backwards. Example for a palindrome is malayalam.
*/

#include<stdio.h> // for printf and scanf
#include<string.h>// for strlen

int isPalindromeIterative(char str[100]){
    int left=0;//starting index
    int right=strlen(str)-1;//ending index

    while(left<right){//compare characters from both ends
        if(str[left]!=str[right]){//mismatch found
            return 0;//not a palindrome
        }
        left++;//move towards center
        right--;//move towards center
    }
    return 1;//palindrome
}

int isPalindromeRecursive(char str[100],int left,int right){
    if(left>=right){//base case: all characters matched
        return 1;//palindrome
    }
    if(str[left]!=str[right]){//mismatch found
        return 0;//not a palindrome
    }
    return isPalindromeRecursive(str,left+1,right-1);//move towards center
}

int main(){
    char str[100];
    printf("Enter the string: ");
    scanf("%s",str);    //simple input without spaces

    if(isPalindromeIterative(str)){//call iterative function
        printf("Iterative:Given string is Palindrome\n");
    }else{
        printf("Iterative:Given string is not Palindrome\n");
    }

    if(isPalindromeRecursive(str,0,strlen(str)-1)){//call recursive function
        printf("Recursive:Given string is Palindrome\n");
    }else{
        printf("Recursive:Given string is not Palindrome\n");
    }

    return 0;
}