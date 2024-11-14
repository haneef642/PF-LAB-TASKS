#include <stdio.h>

int main() {
    int n = 10;  
   

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n - i +1 ; j++) {
            printf(". ");
        }

        for (int j = 0; j < i + 1; j++) {
            printf("o");
        }

        
        printf("\n");
    }    
    printf(". ");
    for (int j = 0; j < n +1 ; j++) {
        printf("o");
    }
    printf("\n");

    
    for (int i = n - 1; i >= 0; i--) {
        
        for (int j = 0; j < n - i + 1; j++) {
            printf(". ");
        }

       
        for (int j = 0; j < i + 1; j++) {
            printf("o");
        }

        
        printf("\n");
    }

    return 0;
}
