#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        int Id;
        double salary;
    public:
    void setname(string n){
        name = n;
    }
    
    void setid(int id){
        Id = id;
    }
    
    void setsalary(double s){
        if(s >= 0){
        salary = s;}
    }

    string getname(){
        return name;
    }
    int getid(){
        return Id;
    }
    double getsalary(){
        return salary;
    }

    void display(){
        cout << "Name " << getname() << endl;
        cout << "ID " << getid() << endl;
        cout << "Salary " << getsalary() << endl;
    }
    };

int main(){
    Employee emp;
        string name;
        int Id;
        double salary;
    cout << "Enter Name: " << endl;
    getline(cin,name);
    emp.setname(name);

    cout << "Enter id: " << endl;
    cin >> Id;
    emp.setid(Id);

    cout << "Enter salary: " << endl;
    cin >> salary;
    emp.setsalary(salary);

    emp.display();
}           