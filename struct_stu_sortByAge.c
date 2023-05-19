#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int age;
    float marks;
};

void sortStudentsByAge(struct Student students[], int numStudents);
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
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    sortStudentsByAge(students, numStudents);

    printf("Sorted student records by age:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}

void sortStudentsByAge(struct Student students[], int numStudents) {
    int i, j;
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (students[j].age > students[j + 1].age) {
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
