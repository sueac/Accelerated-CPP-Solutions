#include <iostream>


//this function deliberately yields an invalid pointer.
//it is intended as a negative example--don't do this!


int* invalid_pointer()
{
	int x;
	return &x; //instant disaster!
	
}

//this function is legit
int* pointer_to_static(){
	static int x;
	return &x;
}

int main() {
	std::cout << pointer_to_static() << std::endl;

}
