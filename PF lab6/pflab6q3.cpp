#include <stdio.h>

int main() {
    int number;

    do {
        printf("Please enter a positive number ");
        scanf("%d", &number);

        if (number <= 0) {
            printf("Try again.\n");
        }
    } while (number <= 0);

    printf("You entered: %d\n", number);
    return 0;
}

