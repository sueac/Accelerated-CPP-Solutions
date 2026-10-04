#ifndef GUARD_List_h
#define GUARD_List_h

#include <cstddef>
#include <stdexcept>


template <class T>
class List {
	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node(const T& d, Node* p, Node* n): data(d), prev(p), next(n) {}

	};



public:
	typedef T value_type;
	typedef std::size_t size_type;

	//end() is represented by a null node pointer; the iterator keeps a pointer to its list so that
	//--end() can find the last element
	class iterator {
		friend class List;
	public:
		iterator(): node(0), owner(0) {}

		T& operator*() const { return node->data; }
		T* operator->() const { return &node->data; }

		iterator& operator++() { node = node->next; return *this; }
		iterator& operator++(int) { iterator t = *this; ++*this; return t; }

		iterator& operator--() {
			node = node ? node->prev : owner->tail;
			return *this;
		}

		iterator& operator--(int) { iterator t = *this; --*this; return t; }

		bool operator==(const iterator& o) const { return node == o.node; }
	 	bool operator!=(const iterator& o) const { return node != o.node; }	

	private:
		iterator(Node* n, List* l): node(n), owner(l) {}
		Node* node;
		List* owner;
	};

	List(): head(0), tail(0), length(0) { }
	List(const List& rhs): head(0), tail(0), length(0) {
		for (Node* p = rhs.head; p; p = p->next)
			push_back(p->data);
	}
	List& operator=(const List& rhs) {
		if (this != &rhs) {
			List tmp(rhs);
			swap(tmp);
		}
		return *this;
	}
	~List() { clear(); }

	//capacity
	size_type size() const { return length; }
	bool empty() const { return length == 0; }

	//iterators
	iterator begin() { return iterator(head, this); }
	iterator end() { return iterator(0, this); } //points at null, which represents one after the tail
	
	//element access
	T& front() { check_not_empty(); return head->data; }
	T& back() { check_not_empty(); return tail->data; }

	// modifiers
	void push_back(const T& x) {
		Node *n = new Node(x, tail, 0);
		if (tail) tail->next = n; else head = n;
		tail = n;
		++length;
	}

	void push_front(const T& x) {
		Node *n = new Node(x, 0, head);
		if (head) head->prev = n; else tail = n;
		head = n;
		++length;
	}

	void pop_back() {
		check_not_empty();
		Node* n = tail;
		tail = n->prev;
		if (tail) tail->next = 0; else head = 0;
		delete n;
		--length;
	}

	void pop_front() {
		check_not_empty();
		Node* n = head;
		head = n->next;
		if (head) head->prev = 0; else tail = 0;
		delete n;
		--length;
	}

	//inserts x before pos, returns an iterator to the new element
	iterator insert(iterator pos, const T& x) {
		if (pos.node == 0) {
			push_back(x);
			return iterator(tail, this);
		}
		if (pos.node == head) {
			push_front(x);
			return iterator(head, this);
		}
		Node* n = new Node(x, pos.node->prev, pos.node);
		pos.node->prev->next = n;
		pos.node->prev = n;
		++length;
		return iterator(n, this);	
	}

	//removes the element at pos; returns an iterator to the following element
	iterator erase(iterator pos) {
		if (pos.node == 0) {
			throw std::domain_error("cannot erase end()");
		}
		Node* n = pos.node;
		Node* following = n->next;
		if (n->prev) n->prev->next = n->next; else head = n->next;
		if (n->next) n->next->prev = n->prev; else tail = n->prev;
		delete n;
		--length;
		return iterator(following, this);
	}

	void clear() {
		while(head) 
			pop_front();
	}

	void swap(List& other) {
		Node* h = head; head = other.head; other.head = h;
		Node* t = tail; tail = other.tail; other.tail = t;
		size_type l = length; length = other.length; other.length = l;
	}

private:
	void check_not_empty() const {
		if (length == 0) 
			throw std::domain_error("list is empty");
	}

	Node* head;
	Node* tail;
	size_type length;
};


#endif
