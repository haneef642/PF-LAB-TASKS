#include <stdio.h>
#include <string.h>

int main() {
    
    char students[5][20] = {"Alice", "Harry", "Charlie", "Diana", "Eve"};
    
    
    char searchName[20];
    int found = 0;
    printf("Enter a name to search: ");
    scanf("%s", searchName);

 
    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i], searchName) == 0) {
            found = 1;
            break;
        }
    }

    
    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

