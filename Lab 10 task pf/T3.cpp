#include <stdio.h>
#include <string.h>

#define MAX_CARS 100  // Maximum number of cars the dealership can store

// Define the structure to store car details
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

// Function prototypes
void addCar(struct Car dealership[], int *carCount);
void displayCars(struct Car dealership[], int carCount);
void searchByMakeOrModel(struct Car dealership[], int carCount, char searchTerm[]);

int main() {
    struct Car dealership[MAX_CARS];  // Array to store cars in the dealership
    int carCount = 0;  // Counter to track the number of cars added
    int choice;
    char searchTerm[50];
    
    while (1) {
        // Display menu options
        printf("\nCar Dealership Menu\n");
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                addCar(dealership, &carCount);
                break;
            case 2:
                displayCars(dealership, carCount);
                break;
            case 3:
                printf("Enter the make or model to search for: ");
                fgets(searchTerm, sizeof(searchTerm), stdin);
                searchTerm[strcspn(searchTerm, "\n")] = 0;  // Remove trailing newline
                searchByMakeOrModel(dealership, carCount, searchTerm);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new car
void addCar(struct Car dealership[], int *carCount) {
    if (*carCount >= MAX_CARS) {
        printf("The dealership is full, cannot add more cars.\n");
        return;
    }

    struct Car newCar;
    printf("Enter car details:\n");
    printf("Make: ");
    fgets(newCar.make, sizeof(newCar.make), stdin);
    newCar.make[strcspn(newCar.make, "\n")] = 0;  // Remove trailing newline

    printf("Model: ");
    fgets(newCar.model, sizeof(newCar.model), stdin);
    newCar.model[strcspn(newCar.model, "\n")] = 0;  // Remove trailing newline

    printf("Year: ");
    scanf("%d", &newCar.year);

    printf("Price: ");
    scanf("%f", &newCar.price);

    printf("Mileage: ");
    scanf("%f", &newCar.mileage);
    getchar();  // To consume the newline character left by scanf

    // Add the car to the dealership
    dealership[*carCount] = newCar;
    (*carCount)++;
    printf("Car added successfully!\n");
}

// Function to display all cars in the dealership
void displayCars(struct Car dealership[], int carCount) {
    if (carCount == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("\nList of cars available:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", dealership[i].make);
        printf("Model: %s\n", dealership[i].model);
        printf("Year: %d\n", dealership[i].year);
        printf("Price: %.2f\n", dealership[i].price);
        printf("Mileage: %.2f\n", dealership[i].mileage);
        printf("------------------------\n");
    }
}

// Function to search for cars by make or model
void searchByMakeOrModel(struct Car dealership[], int carCount, char searchTerm[]) {
    int found = 0;
    for (int i = 0; i < carCount; i++) {
        if (strstr(dealership[i].make, searchTerm) != NULL || strstr(dealership[i].model, searchTerm) != NULL) {
            printf("\nCar found:\n");
            printf("Make: %s\n", dealership[i].make);
            printf("Model: %s\n", dealership[i].model);
            printf("Year: %d\n", dealership[i].year);
            printf("Price: %.2f\n", dealership[i].price);
            printf("Mileage: %.2f\n", dealership[i].mileage);
            printf("------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No car found with the make or model: %s\n", searchTerm);
    }
}

