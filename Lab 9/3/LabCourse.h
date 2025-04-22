#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course {
private:
    double labPerformance;
    double projectScore;

public:
    LabCourse(string code, int cr, double lab, double project);
    void displayInfo() const override;
    double calculateGrade() const override;
};

#endif
