#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const double&, const double&);
double median(std::vector<double>);
double average(double, double);
#endif
