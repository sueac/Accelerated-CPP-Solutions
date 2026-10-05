#ifndef GUARD_MyString_h
#define GUARD_MyString_h

#include <iostream>
#include <algorithm>
#include <cstring>

class MyStr {
	friend std::istream& operator>>(std::istream&, MyStr&);

public:
	typedef size_t size_type;
	typedef char* iterator;
	typedef const char* const_iterator;
	
	MyStr() : value(0), length(0) {}

	MyStr(size_type n, char c) {
		//allocate memory
		length = n;
		value = new char[length];
		
		//fill array with c
		for (size_type i = 0; i != length; ++i)
			value[i] = c;
	}
	
	MyStr(const char* cp) {
		length = std::strlen(cp);
		value = new char[length];

		std::copy(cp, cp + length, value);
	}

	MyStr(const MyStr& s) {
		length = s.length;
		value = new char[length];

		std::copy(s.value, s.value + length, value);
	}

	~MyStr() {
		if (value != 0)
			delete[] value;

	}

	template<class In> MyStr(In b, In e) {
		length = e - b;
		value = new char[length];

		std::copy(b, e, value);
	}

	char& operator[](size_type i) { return *(value + i); }
	const char& operator[](size_type i) const { return value[i]; }
	size_type size() const { return length; }
		
	
	//Q2
	const char* c_str() const { return value + '\0';}
	const char* data() const { return value; }
	void copy(char* p, size_type n) {
		std::copy(value, value + n, p);
	}

	MyStr& operator+=(const MyStr& s) {
		size_type new_length = length + s.length;
		char* new_value = new char[new_length];	
		
		std::copy(value, value + length, new_value);
		std::copy(s.value, s.value + s.length, new_value + length);

		delete[] value;
		value = new_value;
		length = new_length;
		return *this;
	}

	MyStr& operator+=(char c) {
		char* new_value = new char[length + 1];
		std::copy(value, value + length, new_value);
		new_value[length] = c;
		delete[] value;
		value = new_value;
		++length;
		return *this;
	
	}
	
	//Q5
	MyStr& operator+=(const char* s) {
		size_type new_length = length + strlen(s);
		char* new_value = new char[new_length];

		std::copy(value, value + length, new_value);
		std::copy(s, s + strlen(s), new_value);

		delete[] value;
		value = new_value;
		length = new_length;
		return *this;

	}

	//Q6
	explicit operator bool() const { return length != 0; }
	
	//Q7
	iterator begin() { return value; }
	iterator end() { return value + length; }
	const_iterator begin() const { return value; }
	const_iterator end() const { return value + length; }

	MyStr& operator=(const MyStr& rhs) {
   		if (this != &rhs) {
        		char* new_value = new char[rhs.length];
        		std::copy(rhs.value, rhs.value + rhs.length, new_value);
        		delete[] value;
        		value = new_value;
        		length = rhs.length;
    		}
    		return *this;
	}


private:
	char* value;
	size_type length;
};

std::ostream& operator<<(std::ostream&, const MyStr&);
MyStr operator+(const MyStr&, const MyStr&);

//Q3
bool operator<(const MyStr&, const MyStr&);
bool operator<=(const MyStr&, const MyStr&);
bool operator>(const MyStr&, const MyStr&);
bool operator>=(const MyStr&, const MyStr&);

//Q4
bool operator==(const MyStr&, const MyStr&);
bool operator!=(const MyStr&, const MyStr&);

//Q8
std::istream& getline(std::istream&, MyStr&);


#endif
