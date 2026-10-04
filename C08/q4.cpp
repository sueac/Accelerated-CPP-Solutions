//swap is used in reverse because it necessary to use a tmp variable, but we do not know the type of this temp variable from the information given in this function. the swap function automatically figures out the type of *begin and *end. 
//Writing Bi tmp = *begin; doesnt work because Bi is an iterator type 



//8.2.5
//Reversible access
//needs to support a bidirectional iterator


template<class Bi> void reverse(Bi begin, Bi end) {
	while(begin != end) {
		--end;
		if(begin != end) {
			// ?? tmp = *begin;
			*begin = *end;
			*end = tmp;
			++begin;
		}
	}
}




template<class T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = x;
}
