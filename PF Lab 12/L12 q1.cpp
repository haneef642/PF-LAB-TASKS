#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_students, num_grades;

    printf("Enter the total number of students: ");
    scanf("%d", &num_students);

    int **grades = (int **)malloc(num_students * sizeof(int *));
    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        printf("\nEnter the number of grades for student %d: ", i + 1);
        scanf("%d", &num_grades);

        grades[i] = (int *)malloc(num_grades * sizeof(int));
        if (grades[i] == NULL) {
            printf("Memory allocation failed for student %d!\n", i + 1);
            return 1;
        }

        printf("Enter the grades for student %d:\n", i + 1);
        for (int j = 0; j < num_grades; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    printf("\nGrades entered:\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d grades: ", i + 1);
        for (int j = 0; grades[i][j] != '\0'; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_students; i++) {
        free(grades[i]);
    }
    free(grades);

    return 0;
}
