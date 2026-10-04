#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Student_info_q1.h"


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			std::streamsize prec = cout.precision();
			cout << std::setprecision(3) << students[i].final_grade() << std::setprecision(prec) << endl;
		} catch (std::domain_error e) {
			cout << e.what() << endl;
		}

	}

}
