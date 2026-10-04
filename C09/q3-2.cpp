#include "Student_info.h"
#include <iostream>
#include <stdexcept>

using std::domain_error;
using std::cout;
using std::endl;


int main() {
	Student_info student;
	
	try {
		student.grade();
	} catch (domain_error e) {
		cout << e.what() << endl;
	}


}
