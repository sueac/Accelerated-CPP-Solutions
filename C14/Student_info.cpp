#include <iostream>

#include "Core.h"
#include "Student_info.h"

using std::istream;
using std::cout;
using std::endl;

istream& Student_info::read(istream& is) {

	char ch;
	if (!(is >> ch))                // EOF or stream error: stop quietly
		return is;
	

	if (ch == 'U') {
		cp = new Core(is);
	} else if (ch == 'G') {	
		cp = new Grad(is);
	} else if (ch == 'P') {
		cp = new PassFail(is);
	} else if (ch == 'A') {
		cp = new Audit(is);
	} else {
		cout << "Not a valid student" << endl;
		is.setstate(std::ios::failbit);
	}

	return is;

}


