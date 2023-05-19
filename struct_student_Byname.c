#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void sortStudents(struct Student students[], int numStudents);
void swap(struct Student *a, struct Student *b);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, i;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    sortStudents(students, numStudents);

    printf("Sorted student records:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}

void sortStudents(struct Student students[], int numStudents) {
    int i, j;
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}
