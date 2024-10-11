#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

void printFibonacci(int limit) {
    int a = 0, b = 1, next;

    printf("Fibonacci series up to %d: ", limit);
    while (a <= limit) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int number;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
        printFibonacci(number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}

