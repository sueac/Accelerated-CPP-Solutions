#include "Student_info.h"

using std::cout;
using std::endl;

int main() {
	Core* c1 = new Core;

	if (c1->valid()) {
		cout << "Valid student" << endl;
	} else {
		cout << "Not valid" << endl;
	}


}
