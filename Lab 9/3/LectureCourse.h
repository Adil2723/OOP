#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course {
private:
    double examScore;
    double assignmentScore;

public:
    LectureCourse(string code, int cr, double exam, double assignment);
    void displayInfo() const override;
    double calculateGrade() const override;
};

#endif
