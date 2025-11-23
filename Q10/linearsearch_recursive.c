#include<stdio.h>

int linearsearch(int n,int a[],int key,int index){
    if(index>=n){
        return -1;
    }

    if(a[index]==key){
        return index;
    }
    return linearsearch(n,a,key,index+1);
}
int main(){
    int i,n,key;
    printf("Enter the number of elements to be entered in the array:");
    scanf("%d",&n);

    int a[n];
    printf("Enter the %d elements in the array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the key element:\n");
    scanf("%d",&key);


    int result;
    result=linearsearch(n,a,key,0);

    if(result==-1){
        printf("Element not found!");
    }else{
        printf("Element found!");
    }
    return 0;
}