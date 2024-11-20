#include <stdio.h>

void printPercentage(int current, int max) {
    if (current > max) return;  
    printf("%d%%\n", current);  
    printPercentage(current + 1, max);  
}

int main() {
    int maxPercentage;
    
    
    printf("Enter the maximum percentage (1-100): ");
    scanf("%d", &maxPercentage);
    
    
    if (maxPercentage < 1 || maxPercentage > 100) {
        printf("Please enter a valid percentage between 1 and 100.\n");
        return 1;
    }
    
    
    printPercentage(1, maxPercentage);

    return 0;
}

