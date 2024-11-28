#include <stdio.h>
#include <string.h>


struct Employee {
    char name[100];
    char dob[20];          
    int emp_id;            
    char department[50];   
    float salary;          
};


void addEmployee(struct Employee *employees, int *count) {
    if (*count >= 5) {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return;
    }

    struct Employee emp;
    
    
    printf("\nEnter employee name: ");
    getchar();  
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;  

    printf("Enter date of birth (dd-mm-yyyy): ");
    fgets(emp.dob, sizeof(emp.dob), stdin);
    emp.dob[strcspn(emp.dob, "\n")] = 0;  

    printf("Enter employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter department: ");
    getchar();  
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;  

    printf("Enter salary: ");
    scanf("%f", &emp.salary);

    
    employees[*count] = emp;
    (*count)++;
    printf("\nEmployee added successfully.\n");
}


void deleteEmployee(struct Employee *employees, int *count) {
    int emp_id, i, found = 0;
    
    if (*count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    printf("\nEnter the employee ID to delete: ");
    scanf("%d", &emp_id);

    
    for (i = 0; i < *count; i++) {
        if (employees[i].emp_id == emp_id) {
            found = 1;
            
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            printf("Employee with ID %d deleted successfully.\n", emp_id);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", emp_id);
    }
}


void displayEmployees(struct Employee *employees, int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nList of Employees:\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Employee ID: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("------------------------------------------------------------\n");
    }
}

int main() {
    struct Employee employees[5];  
    int count = 0;  
    int choice;

    do {
        
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                deleteEmployee(employees, &count);
                break;
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
