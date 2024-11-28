#include <stdio.h>


struct phone {
    int area_code;  
    int exchange;   
    int number;    
};


void displayPhoneNumber(struct phone p) {
    printf("(%d) %d-%d\n", p.area_code, p.exchange, p.number);
}

int main() {
    
    struct phone myNumber = {212, 767, 8900};
    struct phone yourNumber;  

    
    printf("Enter area code: ");
    scanf("%d", &yourNumber.area_code);

    printf("Enter exchange: ");
    scanf("%d", &yourNumber.exchange);

    printf("Enter number: ");
    scanf("%d", &yourNumber.number);

    
    printf("My number is ");
    displayPhoneNumber(myNumber);

    printf("Your number is ");
    displayPhoneNumber(yourNumber);

    return 0;
}
