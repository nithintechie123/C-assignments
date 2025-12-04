/*
    7. Write a C Program that copies the contents of a binary file
       of integers to a second file.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {

    FILE *source, *target;
    int buffer;  // Used to temporarily store each integer read from the file

    // Open the source binary file in "rb" (read-binary) mode
    // This file should already exist
    source = fopen("source.bin", "rb");
    if (source == NULL) {
        printf("Error opening the source file\n");
        return 1;   // Exit the program if the file cannot be opened
    }

    // Open the target binary file in "wb" (write-binary) mode
    // If the file does not exist, it will be created
    target = fopen("target.bin", "wb");
    if (target == NULL) {
        printf("Error opening the target file\n");
        fclose(source);  // Close the already opened source file
        return 1;
    }

    // Copy integers from source to target
    // fread() reads binary data; it reads 1 integer at a time into 'buffer'
    // The loop continues as long as fread returns 1 (meaning read success)
    while (fread(&buffer, sizeof(int), 1, source) == 1) {

        // Write the integer stored in 'buffer' into the target file
        fwrite(&buffer, sizeof(int), 1, target);
    }

    // Close both files after copying is complete
    fclose(source);
    fclose(target);

    return 0;   // Successful program termination
}
