/*8.Write a C Program that compares two files and returns equal or not equal based on the
 result of comparison?
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    FILE *fp1,*fp2;

    if(argc!=3){
        printf("Invalid Arguments\n");
        return 1;
    }

    fp1=fopen(argv[1],"r");
    if(fp1==NULL){
        printf("Error opening file file1.txt");
        return 1;
    }

    fp2=fopen(argv[2],"r");
    if(fp2==NULL){
        printf("Error opening file file2.txt");
        fclose(fp1);
        return 1;
    }

    int ch1,ch2;

    while(1){
        ch1=fgetc(fp1);
        ch2=fgetc(fp2);

        if(ch1!=ch2){
            printf("Files are not equal\n");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }

        if(ch1==EOF && ch2==EOF){
            printf("Files are equal");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    return 0;
}