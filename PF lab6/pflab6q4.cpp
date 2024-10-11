#include <stdio.h>

int main() {
    int input;
    int sum = 0;

    printf("Enter numbers to add to the sum (enter 0 to stop) \n");

   
    while (1) { 
        printf("Enter a number: ");
        scanf("%d", &input);

        if (input == 0) {
            break; 
        }

        sum += input;
        printf("Current sum  %d\n", sum);
    }

    printf("Final sum  %d\n", sum);
    return 0;
}

