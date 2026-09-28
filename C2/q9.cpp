#include <iostream>
#include <string>

int main() {
	std::cout << "Please enter first number: ";
	int first_num;
	std::cin >> first_num;

	std::cout << "Please enter second number: ";
	int second_num;
	std::cin >> second_num;

	if (first_num > second_num) {
		std::cout << "The first number you entered was larger!" << std::endl;
	} else if (first_num < second_num) {
		std::cout << "The second number you entered was larger!" << std::endl;
	} else {
		std::cout << "Both numbers are equal!" << std::endl;
	}

	return 0;






}
