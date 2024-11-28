#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 3
#define MAX_STUDENTS 5

struct Student {
    int studentID;
    char studentName[50];
    char enrollmentDate[20];
};


struct Instructor {
    int instructorID;
    char instructorName[50];
};


struct Course {
    int courseID;
    char courseName[50];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int studentCount;
};


struct Department {
    int departmentID;
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};


struct Department departments[MAX_DEPARTMENTS];
int departmentCount = 0;


void addDepartment() {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments.\n");
        return;
    }

    struct Department newDept;
    printf("Enter department ID: ");
    scanf("%d", &newDept.departmentID);
    getchar();  

    printf("Enter department name: ");
    fgets(newDept.departmentName, sizeof(newDept.departmentName), stdin);
    newDept.departmentName[strcspn(newDept.departmentName, "\n")] = '\0'; 

    newDept.courseCount = 0;  

    departments[departmentCount++] = newDept;
    printf("Department added successfully.\n");
}


void addCourse() {
    int deptID;
    printf("Enter department ID to add course: ");
    scanf("%d", &deptID);

   
    int deptIndex = -1;
    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1) {
        printf("Department not found.\n");
        return;
    }

    struct Department *dept = &departments[deptIndex];

    if (dept->courseCount >= MAX_COURSES) {
        printf("Cannot add more courses to this department.\n");
        return;
    }

    struct Course newCourse;
    printf("Enter course ID: ");
    scanf("%d", &newCourse.courseID);
    getchar();  

    printf("Enter course name: ");
    fgets(newCourse.courseName, sizeof(newCourse.courseName), stdin);
    newCourse.courseName[strcspn(newCourse.courseName, "\n")] = '\0'; 

    // Add instructor to the course
    printf("Enter instructor ID: ");
    scanf("%d", &newCourse.instructor.instructorID);
    getchar();  // To consume the newline character

    printf("Enter instructor name: ");
    fgets(newCourse.instructor.instructorName, sizeof(newCourse.instructor.instructorName), stdin);
    newCourse.instructor.instructorName[strcspn(newCourse.instructor.instructorName, "\n")] = '\0'; // Remove newline

    newCourse.studentCount = 0;  // Initialize student count to 0

    dept->courses[dept->courseCount++] = newCourse;
    printf("Course added successfully.\n");
}

// Function to add students to a course
void addStudentsToCourse() {
    int deptID, courseID;
    printf("Enter department ID: ");
    scanf("%d", &deptID);

    
    int deptIndex = -1;
    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1) {
        printf("Department not found.\n");
        return;
    }

    struct Department *dept = &departments[deptIndex];

    printf("Enter course ID: ");
    scanf("%d", &courseID);

  
    int courseIndex = -1;
    for (int i = 0; i < dept->courseCount; i++) {
        if (dept->courses[i].courseID == courseID) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    struct Course *course = &dept->courses[courseIndex];

    if (course->studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students to this course.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.studentID);
    getchar();  
    printf("Enter student name: ");
    fgets(newStudent.studentName, sizeof(newStudent.studentName), stdin);
    newStudent.studentName[strcspn(newStudent.studentName, "\n")] = '\0'; 

    printf("Enter enrollment date (DD/MM/YYYY): ");
    fgets(newStudent.enrollmentDate, sizeof(newStudent.enrollmentDate), stdin);
    newStudent.enrollmentDate[strcspn(newStudent.enrollmentDate, "\n")] = '\0'; 

    course->students[course->studentCount++] = newStudent;
    printf("Student added to the course successfully.\n");
}


void displayDepartments() {
    if (departmentCount == 0) {
        printf("No departments to display.\n");
        return;
    }

    for (int i = 0; i < departmentCount; i++) {
        struct Department *dept = &departments[i];
        printf("\nDepartment ID: %d\n", dept->departmentID);
        printf("Department Name: %s\n", dept->departmentName);
        printf("Courses offered:\n");

        for (int j = 0; j < dept->courseCount; j++) {
            struct Course *course = &dept->courses[j];
            printf("\tCourse ID: %d\n", course->courseID);
            printf("\tCourse Name: %s\n", course->courseName);
            printf("\tInstructor: %s (ID: %d)\n", course->instructor.instructorName, course->instructor.instructorID);
            printf("\tEnrolled Students:\n");

            for (int k = 0; k < course->studentCount; k++) {
                struct Student *student = &course->students[k];
                printf("\t\tStudent ID: %d\n", student->studentID);
                printf("\t\tStudent Name: %s\n", student->studentName);
                printf("\t\tEnrollment Date: %s\n", student->enrollmentDate);
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Add Students to Course\n");
        printf("4. Display Departments and Courses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                addStudentsToCourse();
                break;
            case 4:
                displayDepartments();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}
