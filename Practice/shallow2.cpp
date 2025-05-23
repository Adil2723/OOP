#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
    string name;
    string dept;
    string subject;
    float* salary;

public:
  
    Teacher(string name, string dept, string subject, float salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = new float(salary);
    }

   
    Teacher(Teacher &t1) {
        name = t1.name;
        dept = t1.dept;
        subject = t1.subject;
        salary = t1.salary;
    }

   
    void display() {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << *salary << endl;
    }

  
    void changesalary(float newsalary) {
        *salary = newsalary;
    }
};

int main() {
   Teacher t1("John Doe", "Mathematics", "Algebra", 50000.0);
    
    Teacher t2(t1);
    cout << "Teacher 1 details:" << endl;
    t1.display();
    
    cout << "\nTeacher 2 details (shallow copy):" << endl;
    t2.display();
    
    t1.changesalary(50);
    cout << "\nAfter changing subject of Teacher 1:" << endl;
    cout << "Teacher 1 details:" << endl;
    t1.display();
    
    cout << "\nTeacher 2 details (shallow copy):" << endl;
    t2.display(); 

    return 0;
}
