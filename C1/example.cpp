// ask for a person's name, and greet the person
#include <iostream>
#include <string>

int main() {
	//ask for person's name
	std::cout << "Please enter your first name: ";

	//read name
	std::string name;	//define name variable
	std::cin >> name;	//read info
	
	//write greeting
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
