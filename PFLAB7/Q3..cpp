#include <stdio.h>

#define SIZE 12
#define RESULT_SIZE (SIZE / 2)

int main() {
    int arr[SIZE];
    int result[RESULT_SIZE];

    
    printf("Enter 12 numbers \n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < RESULT_SIZE; i++) {
        result[i] = arr[2 * i] + arr[2 * i + 1];
    }

    
    printf("Sum of pairs is\n");
    for (int i = 0; i < RESULT_SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

