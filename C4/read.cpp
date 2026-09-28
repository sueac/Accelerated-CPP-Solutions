#include "read.h"
using std::string;
using std::istream;
using std::vector;

istream& read(istream& in, vector<string>& vec) {
	if (in) {
		vec.clear();

		string x;
		while(in >> x) {
			vec.push_back(x);
		}
		
		in.clear();
	}
	
	return in;
}
