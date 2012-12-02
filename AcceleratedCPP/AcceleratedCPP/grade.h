#ifndef ACCELERATED_CPP_grade_h
#define ACCELERATED_CPP_grade_h

// `grade.h'
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif

