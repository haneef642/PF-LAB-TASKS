#include <stdio.h>


int sum_of_digits(int n) {
    
    if (n == 0) {
        return 0;
    }
    
    return (n % 10) + sum_of_digits(n / 10);
}

int main() {
    int number;
    
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    
    int result = sum_of_digits(number);
    
    
    printf("The sum of digits of %d is: %d\n", number, result);
    
    return 0;
}

