#include<iostream>
#include<string>

using namespace std;

class Teacher{
    private:
    string name;
    string subject;
    public:
    Teacher(string n, string s){
        name = n;
        subject = s;
    }
    void display() const {
        cout << "Teacher " << name << "Subject " << subject << endl; 
    }
};

class School{
    private:
    string name;
    Teacher *teachers[10];
    int teacherCount;


    public:
    School(string name){
        this->name = name;
        teacherCount = 0;
    }

    void addteachers(Teacher *teacher){
        if(teacherCount < 10){
        teachers[teacherCount++] = teacher;
        teacherCount++;
    }
}
    void displayTeachers()const {
        cout << "School Name: " << name << endl;
        cout << "List of Teachers: " << endl;
        for (int i =0 ; teacherCount; i++){
            teachers[i]->display();
        }

    }

};



int main(){

    Teacher t1("Ali", "Math");
    Teacher t2("Aliyan", "Phy");

    School school("APS");
    school.addteachers(&t1);
    school.addteachers(&t2);

    school.displayTeachers();
   
}