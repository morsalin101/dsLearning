//copy content of text file
/*  open a text file, file name will be taken from user
    create another text file and copy all the contents from 1st text file into it.
*/
#include <stdio.h>

int main() {
    char sourceFileName[100], destinationFileName[100];
    FILE *sourceFile, *destinationFile;
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening source file");
        exit(0);
    }

    printf("Enter destination file name: ");
    scanf("%s", destinationFileName);

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error opening destination file");
        fclose(sourceFile);
       exit(0);
    }

    // Copy content from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("Content copied successfully!\n");

    return 0;
}
