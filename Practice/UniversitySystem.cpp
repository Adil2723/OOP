#include<iostream>
#include<string>

using namespace std;

class Student{
    private:
    string name;
    int age;
    
    public:
    Student(string n, int a): name(n), age(a){}

    string getName(){
        return name;
    }
      
    void display() const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Course{
    private:
    string courseName;
    Student *students[50];
    int studentCount;
    public:
    Course(string n): courseName(n), studentCount(0){}

    void addStudents(Student *student){
        students[studentCount] = student;
        studentCount++;
        }

    void displayCourse() const{
        cout << "Course Name: " << courseName << endl;
        for(int i = 0; i<studentCount;i++){
            students[i]->display();
            }
        }

    void searchStudent(const string& name)const{
        bool found = false;
        for(int i = 0; i< studentCount;i++){
            if(students[i]->getName() == name){
               cout << "Student found in the course: " << courseName << endl;
                students[i]->display();
                found = true;
                break;
                }
    }  
    if(!found){
        cout << "Student not found in the course: " << courseName << endl;
    }  
}

};

int main(){
    Course course("Math");
    Course course2("Science");

    Student student1("Adil", 20);
    Student student2("Hasan", 22);
   
    
    course.addStudents(&student1);
    course.addStudents(&student2);


    course.searchStudent("John");
}