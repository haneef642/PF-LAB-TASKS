#include <stdio.h>

#define SIZE 20

int main() {
    int arr[SIZE];

    
    printf("Enter 20 numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Numbers in reverse order:\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

