#include <iostream>
#include <string>

int main() {
	std::cout << "Please enter length: ";

	int length;
	std::cin >> length;

	std::cout << "Please enter width: ";
	int width;
	std::cin >> width;

	std::cout << "Printing triangle..." << std::endl;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	
	std::cout << "Printing square..." << std::endl;

	for (int i = 0; i < length; i++) {
		std::cout << std::string(length, '*') << std::endl;
	}

	std::cout << "Printing rectangle..." << std::endl;

	for (int i = 0; i < length; i++) {
		std::cout << std::string(width, '*') << std::endl;
	}

	return 0;
}
