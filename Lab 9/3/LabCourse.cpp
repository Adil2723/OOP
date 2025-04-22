#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cr, double lab, double project)
    : Course(code, cr), labPerformance(lab), projectScore(project) {}

void LabCourse::displayInfo() const {
    cout << "Lab Course: " << courseCode << " (" << credits << " credits)" << endl;
}

double LabCourse::calculateGrade() const {
    return 0.5 * labPerformance + 0.5 * projectScore;
}
