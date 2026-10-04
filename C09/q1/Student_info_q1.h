#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <vector>
#include <string>
#include <iostream>

class Student_info {
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const { return n;}
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() const;
	double final_grade() {return stored_grade;}
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
	double stored_grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
