#include <iostream>
#include <vector>


template <class A, class B>
bool equal(A start, A end, B start2) {
	while (start != end) {
		if (*start != *start2) {
			return false;
		}
		++start;
		++start2;
	}
	return true;
}

template <class In, class Out>
In search(In b, In e, Out b2, Out e2) {
	while (b != e) {
		In bi = b;
		Out b2i = b2;
		while (*bi == *b2i) {
			++bi; ++b2i;
			if (b2i == e2)
				return b;
			if (bi == e)
				return e;
		}
		++b;
	}
	return e;
}

template <class In, class T>
In find(In b, In e, const T& t) {
	while (b != e) {
		if (*b == t) 
			return b;
		++b;	
	}
	return e;
}

template <class In, class Pred>
In find_if(In b, In e, Pred p) {
	while (b != e) {
		if (p(*b))
			return b;
		++b;	
	}
	return e;
}


template <class In, class Out>
Out copy(In b, In e, Out d) {
	while (b != e) {
		*d = *b;
		++b; ++d;
	}
	return d;
}

template <class In, class Out, class T>
Out remove_copy(In b, In e, Out d, const T& t) {
	while (b != e) {
		if (*b != t) {
			*d = *b;
			++d;
		}
		++b;
	}	
	return d;
}


template <class In, class Out, class Pred>
Out remove_copy_if(In b, In e, Out d, Pred p) {
	while (b != e) {
		if (!p(*b))
			*d = *b;
			++d;
		++b;			
	}
	return d;
}


template <class In, class T>
In remove(In b, In e, const T& t) {
	In i = b;
	while (b != e) {
		if (*b != t) {
			*i = *b;
			++i;	
		}
		++b;
	}
	return i;
}


template <class In, class Out, class Pred>
Out transform(In b, In e, Out d, Pred f) {
	while (b != e) {
		*d = f(*b);
		++d; ++b;
	}
	return d;
}

template <class In, class T>
T accumulate(In b, In e, T t) {
	while (b != e) {
		t += *b;
		++b;
	}
	return t;
}



template <class Bi, class Pred>
Bi partition(Bi b, Bi e, Pred p) {
	while (b != e) {
		while (p(*b)) {
			++b;
			if (b == e) {
				return b;
			}
		} 
		do {
			--e;
			if (b == e)
				return b;
		} while (!p(*e))；
		std::swap(*b, *e);
		++b;
	}
	return b;
}

