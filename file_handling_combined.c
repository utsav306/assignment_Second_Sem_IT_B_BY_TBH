#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void copyFile(const char *sourceFile, const char *destinationFile);
void printMatchingPatterns(const char *filename, const char *pattern);
void appendFile(const char *sourceFile, const char *destinationFile);
void readFileWriteFile(const char *sourceFile, const char *destinationFile);

int main() {
    int choice;
    char sourceFile[50], destinationFile[50], pattern[50];

    printf("1. Copy one file into another file\n");
    printf("2. Print patterns that match a given pattern from a file\n");
    printf("3. Append the content of one text file to another\n");
    printf("4. Read content from one file and write it into another file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the source file name: ");
            scanf("%s", sourceFile);
            printf("Enter the destination file name: ");
            scanf("%s", destinationFile);
            copyFile(sourceFile, destinationFile);
            printf("File copied successfully.\n");
            break;
        case 2:
            printf("Enter the file name: ");
            scanf("%s", sourceFile);
            printf("Enter the pattern to match: ");
            scanf("%s", pattern);
            printMatchingPatterns(sourceFile, pattern);
            break;
        case 3:
            printf("Enter the source file name: ");
            scanf("%s", sourceFile);
            printf("Enter the destination file name: ");
            scanf("%s", destinationFile);
            appendFile(sourceFile, destinationFile);
            printf("Content appended successfully.\n");
            break;
        case 4:
            printf("Enter the source file name: ");
            scanf("%s", sourceFile);
            printf("Enter the destination file name: ");
            scanf("%s", destinationFile);
            readFileWriteFile(sourceFile, destinationFile);
            printf("Content written successfully.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

void copyFile(const char *sourceFile, const char *destinationFile) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, source) != NULL) {
        fputs(buffer, destination);
    }

    fclose(source);
    fclose(destination);
}

void printMatchingPatterns(const char *filename, const char *pattern) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (strstr(buffer, pattern) != NULL) {
            printf("%s", buffer);
        }
    }

    fclose(file);
}

void appendFile(const char *sourceFile, const char *destinationFile) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destinationFile, "a");
    if (destination == NULL) {
        printf("Unable to open the destination file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, source) != NULL) {
        fputs(buffer, destination);
    }

    fclose(source);
    fclose(destination);
}

void readFileWriteFile(const char *sourceFile, const char *destinationFile) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, source) != NULL) {
        fputs(buffer, destination);
    }

    fclose(source);
    fclose(destination);
}

