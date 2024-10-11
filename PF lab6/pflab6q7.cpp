#include <stdio.h>

int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10; 
        sum += digit * digit * digit; 
        num /= 10;
    }

    
    return sum == originalNum;
}

int main() {
    int number;

    printf("Enter a number to check if it's an Armstrong number: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

