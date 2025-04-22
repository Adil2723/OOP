#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cr, double exam, double assignment)
    : Course(code, cr), examScore(exam), assignmentScore(assignment) {}

void LectureCourse::displayInfo() const {
    cout << "Lecture Course: " << courseCode << " (" << credits << " credits)" << endl;
}

double LectureCourse::calculateGrade() const {
    return 0.7 * examScore + 0.3 * assignmentScore;
}
