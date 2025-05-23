 #include<iostream>
#include<string>
using namespace std;

class Employee{
	private:
	int id;
	string name;
	double salary;
	public:
		Employee(){
			id = -1;
			name = "Unknown";
			salary = 0.0;
		}
		Employee(int id, string name, double salary){
			this->id = id;
			this->name = name;
			this->salary = salary;
		}
		Employee(const Employee &e2){
			this->id = e2.id;
            this->name = e2.name;
            this->salary = e2.salary;
		}
		int getid(int id){
			return id;
		}
		string getname(string n){
			return name;
		}
		double getssalary(double s){
			return salary;
		}
		 void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }

   
    ~Employee() {
        cout << "Employee object with ID " << id << " is being destroyed." << endl;
    }
};

int main() {
    
    Employee emp1;
    emp1.display();

    
    Employee emp2(1, "Adil", 50000.0);
    emp2.display();

    
    Employee emp3 = emp2;
    emp3.display();

    return 0;
}
	
