#include <string>
#include <iostream>
#include <list>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::islower;

// Overload the << operator for std::list
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& myList) {
    os << "[";
    
    // Iterate through the list using a range-based loop
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        os << *it;
        
        // Add a comma separator between elements, but not after the last one
        if (std::next(it) != myList.end()) {
            os << ", ";
        }
    }
    
    os << "]";
    return os; // Return the stream to allow chaining (e.g., std::cout << list1 << list2;)
}

bool is_lower_case(string s) {
	if (islower(s[0]))
		return true;
	return false;
}


int main() {
	list<string> words;
	list<string> upper;
	string x;

	while (cin >> x) {
		words.push_back(x);
	}

	list<string>::iterator iter = words.begin();

	while(iter != words.end()) {
		if(!is_lower_case(*iter)){
			upper.push_back(*iter);
			iter = words.erase(iter);	
		} else 
			++iter;
	}
	
	for (list<string>::iterator it = upper.begin(); it != upper.end(); ++it) {
		words.push_back(*it);
	}

	cout << "Lower case and then upper case: " << words << endl;	

}
