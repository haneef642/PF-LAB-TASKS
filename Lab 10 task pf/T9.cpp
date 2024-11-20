#include <stdio.h>
#include <string.h>


struct Employee {
    int emp_id;
    char name[50];
    char department[50];
    float salary;
};


void input_employee_details(struct Employee *emp) {

    printf("Enter Employee ID: ");
    scanf("%d", &emp->emp_id);
    
    
    getchar();
    
    
    printf("Enter Name: ");
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';


    printf("Enter Department: ");
    fgets(emp->department, sizeof(emp->department), stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0';  
    
    
    printf("Enter Salary: ");
    scanf("%f", &emp->salary);
}


void display_employee_details(struct Employee emp) {
    printf("\nEmployee ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    int n;

    
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    
    struct Employee employees[n];

    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        input_employee_details(&employees[i]);
    }

    
    printf("\nEmployee details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        display_employee_details(employees[i]);
    }

    return 0;
}

