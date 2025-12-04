/*
 4.Write a C Program to change the nth character of a file called f1 to M. It takes the
 filename, f1,the value n and the character, M as command-line arguments.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int n;
    char newChar;

    if (argc != 4)
    {
        printf("Invalid Arguments\n");
        return 1;
    }

    n = atoi(argv[2]);
    newChar=argv[3][0];

    fp = fopen(argv[1], "r+");
    if (fp == NULL)
    {
        printf("Error in opening file\n");
        return 1;
    }

    if (fseek(fp, n - 1, SEEK_SET) != 0)
    {
        printf("Error:Cannot move to position %d\n", n);
        fclose(fp);
        return 1;
    }

    fputc(newChar, fp);
    printf("Character at position %d in %s changed to '%c'\n", n, argv[1], newChar);

    fclose(fp);

    return 0;
}