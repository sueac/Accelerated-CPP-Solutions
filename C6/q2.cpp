#include <iostream>
#include "find_urls.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	
	//create a sample test
	
	const string test = "Hello, welcome to my Github! The link to the solutions "
		"that I am current using is https://github.com/altugbakan/accelerated-cpp-solutions"
	       " and the link to the textbook website is https://www.acceleratedcpp.com/";

	vector<string> urls = find_urls(test);

	cout << "Found URLs are: " << endl;
	for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it) {
		cout << *it << endl;
	}
	
	return 0;
}
