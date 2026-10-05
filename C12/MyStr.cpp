#include "MyStr.h"
#include <cstring>
#include <cctype>
#include <iostream>
#include <iterator>

using std::isspace;
using std::ostream;
using std::istream;
using std::ostream_iterator;

ostream& operator<<(ostream& os, const MyStr& s) {
	std::copy(s.begin(), s.end(), ostream_iterator<char>(os));
	return os;
}

istream& operator>>(istream& is, MyStr& s) {
	delete[] s.value;
	s.length = 0;
	s.value = 0;

	char c;
	while(is.get(c) && isspace(c))
		;

	if(is) {
		do s += c;
		while (is.get(c) && !isspace(c));

		if (is)
			is.unget();


	}
	return is;
}

MyStr operator+(const MyStr& s, const MyStr& t) {
	MyStr r = s;
	r += t;
	return r;
}



//Q3
bool operator<(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator>=(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

//Q4
bool operator==(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}


bool operator!=(const MyStr& lhs, const MyStr& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}


//Q8

istream& getline(istream& in, MyStr& s) {
	char c;
	while (in.get(c) && c != '\n')
		s += c;

	return in;



}
