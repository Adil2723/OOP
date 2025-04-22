#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main() {
    Course* c1 = new LectureCourse("CS101", 3, 85, 75);
    Course* c2 = new LabCourse("CS102L", 1, 90, 80);

    c1->displayInfo();
    cout << "Final Grade: " << c1->calculateGrade() << "\n\n";

    c2->displayInfo();
    cout << "Final Grade: " << c2->calculateGrade() << "\n";

    delete c1;
    delete c2;

    return 0;
}
