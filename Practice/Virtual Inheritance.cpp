#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Employee : virtual public Person { 
public:
    string jobTitle;

    Employee(string n, int a, string jt) : Person(n, a), jobTitle(jt) {}

    virtual void displayInfo() override {
        Person::displayInfo();
        cout << "Job Title: " << jobTitle << endl;
    }

    virtual ~Employee() {}
};

class Manager : virtual public Employee {  
public:
    int numSubordinates;

    Manager(string n, int a, string jt, int s) : Employee(n, a, jt), numSubordinates(s) {}

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Number of Subordinates: " << numSubordinates << endl;
    }
};

int main() {
    Manager mgr("Alice", 40, "Senior Manager", 10);
    cout << "Manager Info:" << endl;
    mgr.displayInfo();
    return 0;
}
