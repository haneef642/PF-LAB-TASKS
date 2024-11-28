#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 5


struct Course {
    int courseID;
    char courseName[50];
    char instructorName[50];
    int credits;
};


struct Department {
    char departmentName[50];
    struct Course courses[MAX_COURSES]; 
    int numCourses;  
};


void addDepartment(struct Department *departments, int *numDepartments) {
    if (*numDepartments >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments. Maximum limit reached.\n");
        return;
    }
    
    struct Department newDept;
    
  
    printf("Enter Department Name: ");
    getchar(); 
    fgets(newDept.departmentName, sizeof(newDept.departmentName), stdin);
    newDept.departmentName[strcspn(newDept.departmentName, "\n")] = '\0';  

    
    newDept.numCourses = 0;  
    printf("How many courses in the department? ");
    scanf("%d", &newDept.numCourses);
    
    for (int i = 0; i < newDept.numCourses; i++) {
        struct Course newCourse;

    
        printf("\nEnter details for Course %d\n", i + 1);
        printf("Course ID: ");
        scanf("%d", &newCourse.courseID);

        getchar();  
        printf("Course Name: ");
        fgets(newCourse.courseName, sizeof(newCourse.courseName), stdin);
        newCourse.courseName[strcspn(newCourse.courseName, "\n")] = '\0';  

        printf("Instructor Name: ");
        fgets(newCourse.instructorName, sizeof(newCourse.instructorName), stdin);
        newCourse.instructorName[strcspn(newCourse.instructorName, "\n")] = '\0'; 

        printf("Credits: ");
        scanf("%d", &newCourse.credits);

        
        newDept.courses[i] = newCourse;
    }


    departments[*numDepartments] = newDept;
    (*numDepartments)++;

    printf("Department and courses added successfully.\n");
}


void displayDepartments(struct Department *departments, int numDepartments) {
    if (numDepartments == 0) {
        printf("No departments to display.\n");
        return;
    }

    for (int i = 0; i < numDepartments; i++) {
        printf("\nDepartment: %s\n", departments[i].departmentName);
        printf("Courses:\n");

        for (int j = 0; j < departments[i].numCourses; j++) {
            printf("Course ID: %d\n", departments[i].courses[j].courseID);
            printf("Course Name: %s\n", departments[i].courses[j].courseName);
            printf("Instructor: %s\n", departments[i].courses[j].instructorName);
            printf("Credits: %d\n", departments[i].courses[j].credits);
            printf("-----------------------------\n");
        }
    }
}


void calculateTotalCredits(struct Department *departments, int numDepartments) {
    if (numDepartments == 0) {
        printf("No departments to calculate total credits.\n");
        return;
    }

    for (int i = 0; i < numDepartments; i++) {
        int totalCredits = 0;
        for (int j = 0; j < departments[i].numCourses; j++) {
            totalCredits += departments[i].courses[j].credits;
        }
        printf("\nTotal Credits in Department %s: %d\n", departments[i].departmentName, totalCredits);
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int numDepartments = 0;
    int choice;

    do {
        
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add a Department and Courses\n");
        printf("2. Display All Departments and Courses\n");
        printf("3. Calculate Total Credits for Each Department\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(departments, &numDepartments);
                break;
            case 2:
                displayDepartments(departments, numDepartments);
                break;
            case 3:
                calculateTotalCredits(departments, numDepartments);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
