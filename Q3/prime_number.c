/*3. Write a C program to generate all the prime numbers between 1 and n, where n is a
 value supplied by the us*/
 #include<stdio.h>
 int main(){
    int n,i,j,flag;//flag is used to check whether the number is prime or not
    printf("Enter a positive integer:");
    scanf("%d",&n);

    printf("Prime numbers from 1 to %d are :",n);

    for(i=2;i<=n;i++){//loop from 2 to n
        flag=1;//assume the number is prime
        for(j=2;j<=i/2;j++){//check for factors from 2 to i/2
            if(i%j==0){//if i is divisible by j, then it is not prime
                flag=0;//set flag to 0
                break;//exit the loop
            }
        }
        if(flag==1){//if flag is still 1, then i is prime
            printf("%d ",i);//print the prime number
        }
    }
 }