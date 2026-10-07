#ifndef GUARD_Core_h
#define GUARD_Core_h


#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <string>
#include "Ptr.h"

class Core {
public:
	Core(): midterm(0), final(0) {
		//Q1
		//std::cerr << "Core::Core()" << std::endl;
	}
	Core(std::istream& is) { 
		//Q1
		//std::cerr << "Core::Core(istream&)" << std::endl;
		read(is); 
	}

	std::string name() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;
	virtual ~Core() { }
	virtual bool valid() const { return !homework.empty(); } //Q3
	virtual std::string letter_grade() const; //Q4
	virtual bool meets_req() const { return valid(); } //Q5


protected:
	//accessible to derived callses
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }

private:
	//accessible only to 'Core'
	std::string n;
	friend class Student_info;
};

class Grad: public Core {
public:
	Grad(): thesis(0) {
		//Q1
       		//std::cerr << "Grad::Grad()" << std::endl;
	}
	Grad(std::istream& is) { 
		//Q1
		//std::cerr << "Grad::Grad(istream&)" << std::endl;	
		read(is); 
	}

	double grade() const;
	std::istream& read(std::istream&);
	bool meets_req() const { return thesis != 0; } //Q5
private:
	double thesis;
	Grad* clone() const { return new Grad(*this); }
};

class PassFail: public Core {
public:
	PassFail() {}
	PassFail(std::istream& is) {
		read(is);
	}
	double grade() const;
	bool valid() const { return midterm > 0 && final > 0; }
	std::string letter_grade() const { return grade() > 60 ? "P" : "F"; }
protected:
	PassFail* clone() const { return new PassFail(*this); }
};

class Audit: public PassFail {
public:
	Audit() {}
	Audit(std::istream& is) {
		read(is);
	}
	bool valid() const { return name().size() > 0; }
	std::string letter_grade() const { return "N/A"; }
protected:
	Audit* clone() const { return new Audit(*this); }

};






bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core* cp1, const Core* cp2);
bool compare_ptr(const Ptr<Core>&, const Ptr<Core>&);

#endif
