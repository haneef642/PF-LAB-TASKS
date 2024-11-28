#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "books.txt"

struct Book {
    int bookID;
    char title[50];
    char author[50];
    int quantity;
    float price;
};


void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a new Book\n");
    printf("2. View all Books\n");
    printf("3. Search a Book by ID\n");
    printf("4. Search a Book by Title\n");
    printf("5. Update Book Details\n");
    printf("6. Delete a Book\n");
    printf("7. Calculate Total Inventory Value\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}


void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.bookID);
    getchar(); // To consume the newline character after scanf

    // Check for duplicate ID
    FILE *checkFile = fopen(FILENAME, "r");
    if (checkFile != NULL) {
        struct Book existingBook;
        while (fread(&existingBook, sizeof(struct Book), 1, checkFile)) {
            if (existingBook.bookID == newBook.bookID) {
                printf("Duplicate Book ID found! Book not added.\n");
                fclose(checkFile);
                fclose(file);
                return;
            }
        }
        fclose(checkFile);
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 

    printf("Enter Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 

    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);

    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    
    fwrite(&newBook, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book added successfully.\n");
}


void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    printf("\nBook ID\tTitle\tAuthor\tQuantity\tPrice\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("%d\t%s\t%s\t%d\t%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }
    fclose(file);
}


void searchBookByID() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int searchID;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchID);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID == searchID) {
            printf("\nBook ID: %d\n", book.bookID);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Quantity: %d\n", book.quantity);
            printf("Price: %.2f\n", book.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}


void searchBookByTitle() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char searchTitle[50];
    getchar(); 
    printf("Enter Book Title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; 

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (strstr(book.title, searchTitle) != NULL) { 
            printf("\nBook ID: %d\n", book.bookID);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Quantity: %d\n", book.quantity);
            printf("Price: %.2f\n", book.price);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}


void updateBook() {
    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int updateID;
    printf("Enter Book ID to update: ");
    scanf("%d", &updateID);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID == updateID) {
            found = 1;
            fseek(file, -sizeof(struct Book), SEEK_CUR); 
            
      
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new Price: ");
            scanf("%f", &book.price);

            fwrite(&book, sizeof(struct Book), 1, file);
            printf("Book details updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book ID not found.\n");
    }

    fclose(file);
}


void deleteBook() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int deleteID;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteID);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID != deleteID) {
            fwrite(&book, sizeof(struct Book), 1, tempFile); 
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);  
        rename("temp.txt", FILENAME);  
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}


void calculateInventoryValue() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    float totalValue = 0;
    struct Book book;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        totalValue += book.quantity * book.price;
    }

    printf("\nTotal Inventory Value: %.2f\n", totalValue);

    fclose(file);
}

int main() {
    int choice;

    
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fclose(file);

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBookByID();
                break;
            case 4:
                searchBookByTitle();
                break;
            case 5:
                updateBook();
                break;
            case 6:
                deleteBook();
                break;
            case 7:
                calculateInventoryValue();
                break;
            case 8:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
