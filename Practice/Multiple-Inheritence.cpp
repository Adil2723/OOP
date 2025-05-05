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

class Job {
public:
    string jobTitle;
    int salary;

    Job(string jt, int s) : jobTitle(jt), salary(s) {}

    virtual void displayJob() {
        cout << "Job Title: " << jobTitle << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual ~Job() {}
};

class Employee : public Person, public Job {
public:
    Employee(string n, int a, string jt, int s) : Person(n, a), Job(jt, s) {}

    void displayInfo() override {
        Person::displayInfo();
        Job::displayJob();
    }
};

int main() {
    Employee emp("Adil", 19, "Unemployed", 0);
    emp.displayInfo();
    return 0;
}
