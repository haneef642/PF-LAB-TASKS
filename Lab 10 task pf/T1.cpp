#include <stdio.h>
#include <string.h>


void reverseString(char str[], int start, int end) {
    
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    
    reverseString(str, start + 1, end - 1);
}

int main() {
    char sentence[100]; 

    
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    int len = strlen(sentence);
    
    reverseString(sentence, 0, len - 1);

    printf("Reversed sentence: %s\n", sentence);

    return 0;
}

