#include<iostream>
#include<string>

using namespace std;

class Project{
    private:
    string title;
    string deadline;
    Employee *employeeList;
    Project *nextProject ;
    int count = 0;
    public:
    Project(const string& title, const string& deadline)
    : title(title), deadline(deadline), employeeList(nullptr), nextProject(nullptr) {}

    void addemployees(Employee *employees){
        employeesList(count++) = employees;
    }

    void display{
        
    }

};

class Employee{
    private:
    string name;
    string designation;
    Employee *employeelist;
    Project *nextprojects;

}