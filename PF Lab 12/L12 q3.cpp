#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 4, size = 0;
    float *arr = (float *)malloc(capacity * sizeof(float));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        int choice;
        printf("\n1. Add a new number\n2. Display all numbers\n3. Remove the last number\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (size == capacity) {
                capacity *= 2;
                arr = (float *)realloc(arr, capacity * sizeof(float));
                if (arr == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
            }
            printf("Enter a floating-point number: ");
            scanf("%f", &arr[size]);
            size++;
        } else if (choice == 2) {
            printf("Array contents: ");
            for (int i = 0; i < size; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
        } else if (choice == 3) {
            if (size > 0) {
                size--;
                printf("Removed the last number. New size: %d\n", size);
            } else {
                printf("Array is empty.\n");
            }
        } else if (choice == 4) {
            if (size < capacity / 2) {
                capacity = size;
                arr = (float *)realloc(arr, capacity * sizeof(float));
                if (arr == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
            }
            free(arr);
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
