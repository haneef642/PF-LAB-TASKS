#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    string name;
    int age;

public:
    
    void setName(const string& personName) {
        name = personName;
    }
    string getName() const {
        return name;
    }

    
    void setAge(int personAge) {
        age = personAge;
    }
    int getAge() const {
        return age;
    }

    
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
    }

   
    virtual ~Person() {}
};


class Employee : public Person {
private:
    int employeeID;

public:
    
    void setEmployeeID(int id) {
        employeeID = id;
    }

   
    void displayInfo() const override {
        Person::displayInfo();  
        cout << "Employee ID: " << employeeID << endl;
    }
};


class Student : public Person {
private:
    int studentID;

public:
    
    void setStudentID(int id) {
        studentID = id;
    }

    
    void displayInfo() const override {
        Person::displayInfo();  
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
  
    Person person;
    Employee employee;
    Student student;

    
    person.setName("John Doe");
    person.setAge(40);
    cout << "Person Info: " << endl;
    person.displayInfo();
    cout << endl;

    
    employee.setName("Alice Smith");
    employee.setAge(30);
    employee.setEmployeeID(12345);
    cout << "Employee Info: " << endl;
    employee.displayInfo();
    cout << endl;


    student.setName("Bob Johnson");
    student.setAge(20);
    student.setStudentID(98765);
    cout << "Student Info: " << endl;
    student.displayInfo();

    return 0;
}

