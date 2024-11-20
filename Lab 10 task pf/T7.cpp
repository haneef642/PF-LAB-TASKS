#include <stdio.h>


void bubble_sort_pass(int arr[], int n) {
    if (n == 1) {
        return;  
    }

    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }


    bubble_sort_pass(arr, n - 1);
}


void bubble_sort(int arr[], int n) {
    bubble_sort_pass(arr, n);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    bubble_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

