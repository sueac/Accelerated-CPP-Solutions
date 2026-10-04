#include <string>
#include <iostream>
#include <iomanip>

int get_num_length(int number) {
	int count = 0;
	while ( number > 0 ) {
		number /= 10;
		count++;
	}
	return count;
}

int main() {

	/*
	for (int i = 1; i < 1000; i++) {
		std::cout << std::left << std::setw(5) << i << i*i << std::endl;
	}
	*/
	
	const int max_num = 9999;
	
	for (int i = 1; i < max_num; i++) {
		std::cout << std::setw(get_num_length(max_num)) << i << std::setw(get_num_length(max_num*max_num) + 2) << i * i << std::endl;
	}
	return 0;
}

