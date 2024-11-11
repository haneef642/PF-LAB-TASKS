#include <stdio.h>

int main() {
    int matrix[4][4];  
    int i, j;

    
    printf("Enter the grades for 4 students in 4 subjects (a total of 16 grades) \n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Enter grade for student %d in subject %d ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);

            
            if (matrix[i][j] < 0) {
                printf("Invalid grade! Replacing with 0.\n");
                matrix[i][j] = 0;
            }
        }
    }

    printf("\nUpdated matrix with valid grades (negative grades replaced with 0) \n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

