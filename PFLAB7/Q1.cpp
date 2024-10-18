#include <stdio.h>

#define SIZE 5

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50}; 
    int number, found = 0;

    
    printf("Enter a number for search: ");
    scanf("%d", &number);


    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == number) {
            printf("Number %d found at index %d.\n", number, i);
            found = 1;
            break; 
        }
    }

    
    if (!found) {
        printf("Number %d not found in the array.\n", number);
    }

    return 0;
}

