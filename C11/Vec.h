#ifndef GUARD_Vec
#define GUARD_Vec

#include <memory>
#include <algorithm>


template <class T> class Vec {
public: 
	//interface
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	Vec() { create();}
	explicit Vec(size_type n, const T& val()) { create(n, val); }

	//copy function
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	
	//equal operator
	Vec& operator=(const Vec&);

	//destructor
	~Vec() {uncreate(); }

	//new operations: size and index
	size_type size() const { return limit - data; }
	
	//new functions to return iterators
	iterator begin() {return data;}
	const_iterator begin() const {return data;}

	iterator end() {return limit;}
	const_iterator end() const {return data;}

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	void push_back(const T& val) {
		if (avail == limit)	//get space if needed
			grow();
		unchecked_append(val);	//append the new element
	}

	void clear() {
		uncreate();
	}

	iterator erase(iterator);
	iterator erase(iterator, iterator);
	
	bool empty() const { return data == avail; }


private:
	//implementation
	iterator data;	// first element in the Vec
	iterator avail;
	iterator limit;	// one past the last element in the Vec
	
	//facilities for memory allocation
	allocator<T> alloc;

	//allocate and initialize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	//destory the elements in the array and free the memory
	void uncreate();

	//support functions for push_back
	void grow();
	void unchecked_append(const T&);


};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) 
{
    // check for self-assignment
    if (&rhs != this) {

        // free the array in the left-hand side
        uncreate();

        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}


template <class T> void Vec<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j-i);
	limit = avail = uninitialized_copy(i,j,data);
}

template <class T> void Vec<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;

}

template <class T> void Vec<T>::grow() {
	//when growing, allocate twice as much space as currently in use
	size_type new_size = max(2* (limit-data), ptrdiff_t(1));

	//allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);

	//return old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

//assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}


template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator it)
{
	return erase(it, it+1);
}


template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator b, iterator e)
{
	if (b == e)
		return b;

	iterator new_avail = std::copy(e, avail, b);

	iterator it = avail;
	while (it != new_avail)
		alloc.destroy(--it);

	avail = new_avail;
	return b;
}

#endif
