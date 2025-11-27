/*
20. Write a C program that uses functions to perform the following:
 i) addition of two matrices ii) multiplication of two matrices.
*/


#include<stdio.h>

//Function to input a matrix
void inputMatrix(int rows,int cols,int mat[rows][cols]){
    int i,j;
    printf("Enter the elements of the matrix (%d x %d):\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

////Function to display a Matrix
void displayMatrix(int rows,int cols,int mat[rows][cols]){
    int i,j;
    printf("Matrix (%d x %d):\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

//Function for Matrix Addition
void addMatrices(int rows,int cols,int A[rows][cols],int B[rows][cols],int C[rows][cols]){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

//Function for Matrix Multiplication
void multiplayMatrices(int r1,int c1,int r2,int c2,int A[r1][c1],int B[r2][c2],int C[r1][c2] ){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            C[i][j]=0;
            for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

int main(){
    int r1,c1,r2,c2;

    //------MATRIX A----------
    printf("Enter rows and columns for matrix A:");
    scanf("%d %d",&r1, &c1);
    int A[r1][c1];
    inputMatrix(r1,c1,A);

    //------MATRIX B----------
    printf("Enter rows and columns for matrix B:");
    scanf("%d %d",&r2, &c2);
    int B[r2][c2];
    inputMatrix(r2,c2,B);

    //-------Diplay Matrices
    displayMatrix(r1,c1,A);
    displayMatrix(r2,c2,B);

    //-------Matrix Addition---------
    if(r1==r2 && c1==c2){
        int add[r1][c1];
        addMatrices(r1,c1,A,B,add);
        printf("\nAddition Matrix:\n");
        displayMatrix(r1,c1,add);
    }else{
        printf("\nMatrix Addition not possible for given dimensions.\n");
    }

    //-----Matrix Multiplication------
    if(c1==r2){
        int mul[r1][c2];
        multiplayMatrices(r1,c1,r2,c2,A,B,mul);
        printf("\nMultiplication Result:\n");
        displayMatrix(r1,c2,mul);
    }else{
        printf("\nMatrix Multiplication not possible for given dimensions! (c1!=r2)\n");
    }






}