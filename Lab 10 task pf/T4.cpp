#include <stdio.h>
#include <string.h>


#define MAX_PACKAGES 10


typedef struct {
    char package_name[100];
    char destination[100];
    int duration;      
    float cost;        
    int seats_available; 
} TravelPackage;


void display_package_info(TravelPackage package) {
    printf("Package Name: %s\n", package.package_name);
    printf("Destination: %s\n", package.destination);
    printf("Duration: %d days\n", package.duration);
    printf("Cost: $%.2f\n", package.cost);
    printf("Seats Available: %d\n", package.seats_available);
    printf("----------------------------------------\n");
}


void display_available_packages(TravelPackage packages[], int num_packages) {
    printf("Available Travel Packages:\n");
    for (int i = 0; i < num_packages; i++) {
        printf("%d. ", i + 1); 
        display_package_info(packages[i]);
    }
}


void book_travel_package(TravelPackage packages[], int num_packages) {
    int package_choice;
    
    printf("Enter the number of the package you want to book (0 to cancel): ");
    scanf("%d", &package_choice);
    
    if (package_choice == 0) {
        printf("Booking canceled.\n");
        return;
    }

    
    if (package_choice >= 1 && package_choice <= num_packages) {
        TravelPackage *selected_package = &packages[package_choice - 1];
        
        if (selected_package->seats_available > 0) {
            selected_package->seats_available -= 1;
            printf("Booking successful! Seats remaining: %d\n", selected_package->seats_available);
        } else {
            printf("Sorry, no seats available for this package.\n");
        }
    } else {
        printf("Invalid package number. Please try again.\n");
    }
}
int main() {
    
    TravelPackage packages[MAX_PACKAGES] = {
        {"Sunny Beach Escape", "Hawaii", 7, 1200.00, 10},
        {"Mountain Adventure", "Switzerland", 10, 1800.00, 5},
        {"Cultural Tour", "Japan", 14, 2500.00, 2}
    };
    
    int num_packages = 3; 
    char user_input[10];

    while (1) {
        
        display_available_packages(packages, num_packages);
        
        
        printf("Enter 'b' to book a package or 'q' to quit: ");
        scanf("%s", user_input);

        
        if (user_input[0] == 'b' || user_input[0] == 'B') {
            book_travel_package(packages, num_packages);
        }
        
        else if (user_input[0] == 'q' || user_input[0] == 'Q') {
            printf("Exiting the program. Thank you!\n");
            break;
        } else {
            printf("Invalid input. Please enter 'b' to book or 'q' to quit.\n");
        }
    }

    return 0;
}

