#include <stdio.h>

int main() {
    int m, n;  
    int matrix1[50][50], matrix2[50][50], result[50][50];  
    int i, j;

    
    printf("Enter the number of rows (m) and columns (n) for the matrices: ");
    scanf("%d %d", &m, &n);

    
    printf("Enter the elements of the first matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    
    printf("Enter the elements of the second matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }


    printf("\nThe resulting matrix after addition is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

