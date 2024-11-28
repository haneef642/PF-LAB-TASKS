#include <stdio.h>
#include <ctype.h>  

int main() {
    FILE *sourceFile, *destFile;  
    char ch;                      

    char sourceFilename[100];     
    char destFilename[100];       

    
    printf("Enter the source file name: ");
    scanf("%s", sourceFilename);
    printf("Enter the destination file name: ");
    scanf("%s", destFilename);


    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        
        perror("Error opening source file");
        return 1;
    }
    
    destFile = fopen(destFilename, "w");
    if (destFile == NULL) {
        
        perror("Error opening destination file");
        fclose(sourceFile);  
        return 1;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        
        if (ch >= 'a' && ch <= 'z') {
            ch = toupper(ch);  
        }

        
        fputc(ch, destFile);
    }

    
    fclose(sourceFile);
    fclose(destFile);

    printf("File copied successfully with lowercase characters converted to uppercase.\n");

    return 0;
}
