#include <stdio.h>

#define SIZE 10

int main() {
	
	
    int arr[SIZE];
    
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }


    int firstElement = arr[0];


    for (int i = 0; i < SIZE - 1; i++) {
        arr[i] = arr[i + 1];
    }


    arr[SIZE - 1] = firstElement;

    printf("Array after shifting left:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

