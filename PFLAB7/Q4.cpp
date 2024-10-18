#include <stdio.h>

#define SIZE 15

int main() {
    int arr[SIZE];
    int sum = 0;

    
    printf("Enter 15 numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    
    printf("Sum of the elements: %d\n", sum);

    return 0;
}

