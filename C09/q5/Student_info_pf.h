#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <vector>
#include <string>
#include <iostream>

class Student_info_pf {
public:
	Student_info_pf();
	Student_info_pf(std::istream&);
	std::string name() const { return n;}
	std::istream& read(std::istream&);
	double grade() const;
private:
	std::string n;
	double midterm, final;
};

bool compare(const Student_info_pf&, const Student_info_pf&);

#endif
