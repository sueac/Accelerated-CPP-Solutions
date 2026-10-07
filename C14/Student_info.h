#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"

class Student_info {
public:
	Student_info(): cp(0) { }
	Student_info(std::istream& is): cp(0) { read(is); }

	
	std::istream& read(std::istream&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}
	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}
	
	//Q3	
	bool valid() const {
		if (cp) return cp->valid();
		else throw std::runtime_error("uninitialized Student");
	}

	std::string letter_grade() const {
		if (cp) return cp->letter_grade();
		else throw std::runtime_error("uninitialized Student");
	}

	bool meets_req() const {
		if (cp) return cp->meets_req();
		else throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

private:
	Ptr<Core> cp;
};

#endif
