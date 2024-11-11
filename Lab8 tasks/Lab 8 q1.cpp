#include <stdio.h>

int main() {
    int matrix[3][3];  
    int rowSum[3] = {0, 0, 0};  
    int colSum[3] = {0, 0, 0};  
    int i, j;

    
    printf("Enter the scores for a 3x3 matrix (3 participants x 3 activities)  \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter score for participant %d in activity %d  ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (i = 0; i < 3; i++) {
        rowSum[i] = 0;  
        for (j = 0; j < 3; j++) {
            rowSum[i] += matrix[i][j];  
        }
    }

    
    for (j = 0; j < 3; j++) {
        colSum[j] = 0;  
        for (i = 0; i < 3; i++) {
            colSum[j] += matrix[i][j];  
        }
    }


    printf("\nThe matrix of scores is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    
    printf("\nSum of each row (total score of each participant):\n");
    for (i = 0; i < 3; i++) {
        printf("Participant %d  %d\n", i + 1, rowSum[i]);
    }


    printf("\nSum of each column (total score of each activity):\n");
    for (j = 0; j < 3; j++) {
        printf("Activity %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}

