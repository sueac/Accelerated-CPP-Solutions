#ifndef GUARD_Ref_count
#define GUARD_Ref_count

#include <cstddef>

class Ref_count {
public:
	Ref_count(): n(new std::size_t(1)) {}
	Ref_count(const Ref_count& r): n(r.n) { ++*n; }
	~Ref_count() { if (--*n == 0) delete n; }

	bool unique() const { return *n == 1;}

	bool reattach(const Ref_count& rhs) {
		++*rhs.n;
		bool last = (--*n == 0);
		if (last) delete n;
		n = rhs.n;
		return last;
	}

	bool make_unique() {
		if (*n == 1) return false;
		std::size_t* fresh = new std::size_t(1);
		--*n;
		n = fresh;
		return true;
	}
private:
	std::size_t* n;
	Ref_count& operator=(const Ref_count&);
};


#endif
