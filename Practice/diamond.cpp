#include<iostream>
#include<string>

using namespace std;

class Person {
protected:
    int ID;
    string name;

public:
    Person(int ID, string name) : ID(ID), name(name) {}
    
    virtual void displaydetails() {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
    }

    virtual ~Person() {
        cout << "Person object is destroyed" << endl;
    }
};

class Employee : virtual public Person {
protected:
    float salary;

public:
    Employee(int ID, string name, float salary) : Person(ID, name), salary(salary) {}

    void displaydetails() override {
        Person::displaydetails();
        cout << "Salary: " << salary << endl;
    }

    virtual ~Employee() {
        cout << "Employee object is destroyed" << endl;
    }
};

class Student : virtual public Person {
protected:
    float GPA;

public:
    Student(int ID, string name, float GPA) : Person(ID, name), GPA(GPA) {}

    void displaydetails() override {
        Person::displaydetails();
        cout << "GPA: " << GPA << endl;
    }

    virtual ~Student() {
        cout << "Student object is destroyed" << endl;
    }
};

class TeachingAssistent : public Employee, public Student {
protected:
    float hoursWorked;

public:
    TeachingAssistent(int ID, string name, float salary, float GPA, float hoursWorked)
        : Person(ID, name), Employee(ID, name, salary), Student(ID, name, GPA), hoursWorked(hoursWorked) {}

    void displaydetails() override {
        Person::displaydetails();
        cout << "Salary: " << salary << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
    }

    ~TeachingAssistent() {
        cout << "TeachingAssistent object is destroyed" << endl;
    }
};

int main() {
    TeachingAssistent TA(1, "Adil Saeed", 50000, 3.5, 10);
    TA.displaydetails();

    return 0;
}
