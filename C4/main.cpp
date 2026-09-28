#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cout; using std::setprecision;
using std::cin;  using std::sort;
using std::domain_error;
using std::streamsize;
using std::endl; using std::string;
using std::max;  using std::vector;


int main() {

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		streamsize prec = cout.precision();		
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);

		cout << endl;
	}
	return 0;	

}
