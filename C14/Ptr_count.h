#ifndef GUARD_Ptr_count
#define GUARD_Ptr_count

#include <cstddef>
#include <stdexcept>
#include "Ref_count.h"

template <class T> T* clone(const T* tp);

template <class T> class Ptr {
public:
	void make_unique() {
		if (refs.make_unique())
			p = p ? clone(p) : 0;
	}
	
	Ptr(): p(0) {}
	Ptr(T* t): p(t) {}
	Ptr(const Ptr& h): p(h.p), refs(h.refs) {}
	
	Ptr& operator=(const Ptr& rhs) {
		if (refs.reattach(rhs.refs))
			delete p;
		p = rhs.p;
		return *this;
	}

	~Ptr() {
		if (refs.unique())
			delete p;
	}
	
	operator bool() const { return p;}
	T& operator *() const {
		if (p) return *p;
		throw std::runtime_error("Unbound ptr");
	}
	T* operator->() const {
		if (p) return p;
		throw std::runtime_error("Unbound ptr");
	}

private:
	T* p;
	Ref_count refs;

};

template <class T> T* clone (const T* tp) {
	return tp->clone();
}

#endif
