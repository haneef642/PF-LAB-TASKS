#include <stdio.h>

void sortColumn(int matrix[4][4], int col) {
    int temp;
    
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (matrix[i][col] > matrix[j][col]) {
                
                temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

int main() {
    int matrix[4][4];  
    int i, j;

    
    printf("Enter the scores for a 4x4 matrix (3 teams x 3 rounds + 1 extra row):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Enter score for team %d in round %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    printf("\nOriginal matrix:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    
    for (j = 0; j < 4; j++) {
        sortColumn(matrix, j);
    }


    printf("\nMatrix after sorting each column in ascending order:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

