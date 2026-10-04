#include <string>
#include <iostream>
#include "String_list.h"

using std::string;
using std::copy;

String_list::String_list(): length(0), values(new string[0]) {}

void String_list::push_back(string s){
	string* old_values = values;

	//increment the length
	++length;

	string* new_values = new string[length];

	copy(old_values, old_values + length - 1, new_values);
	delete[] old_values;

	//set new values
	values = new_values;
	values[length - 1] = s;
}

string String_list::pop_back() {
	string* old_values = values;

	--length;

	string ret = *end();

	string* new_values = new string[length];

	copy(old_values, old_values + length, new_values);
	delete[] old_values;

	values = new_values;

	return ret;
}
