#ifndef RDVECTOR_H
#define RDVECTOR_H
#pragma once
#include <initializer_list>
#include <algorithm>
#include <iostream>

template <typename T>
class RdVector
/*
	invariant:
	if 0<=n<sz, elem[n] is element n
	sz<=space;
	if sz<space there is space for (space–sz) Ts after elem[sz–1]
*/
{
	size_t sz;    // the size
	T* elem; // pointer to the elements (or 0)
	size_t space; // number of elements plus number of free slots
public:
	RdVector() : sz{ 0 }, elem{ nullptr }, space{ 0 } {} // default constructor
	explicit RdVector(size_t s); // explicit one argument constructor
	explicit RdVector(std::initializer_list<T> lst); // initializer-list constructor
	RdVector(const RdVector&);            // copy constructor
	RdVector& operator=(const RdVector&); // copy assignment
	RdVector(RdVector&& a);               // move constructor
	RdVector& operator=(RdVector&&);      // move assignment
	~RdVector();
	T& operator[](int n) { return elem[n]; }      // for non-const vectors
	const T& operator[](int n) const { return elem[n]; } // for const vectors
	size_t size() const { return sz; }
	size_t capacity() const { return space; }
	void reserve(size_t newalloc);
	void resize(size_t newsize);
	void push_back(const T& d);

	friend std::ostream& operator<<(std::ostream& os, const RdVector& v) {
		os << '[';
		for (size_t i = 0; i < v.size(); ++i) {
			os << ' ' << v[i];
		}
		os << " ]\n";
		return os;
	}
};


template <typename T>
RdVector<T>::RdVector(size_t s)
	: sz{ s }, elem{ new T[s] }, // uninitialized memory for elements
	space{ s }
{
	for (size_t i = 0; i < sz; ++i) {
		elem[i] = T{}; // initialize
	}
}

template <typename T>
RdVector<T>::RdVector(std::initializer_list<T> lst)
	: sz{ lst.size() }, elem{ new T[sz] }, // uninitialized memory
	space{ sz }
{
	std::copy(lst.begin(), lst.end(), elem);
}

template <typename T>
RdVector<T>::RdVector(const RdVector<T>& a)
	: sz{ a.sz }, elem{ new T[sz] }, space{ a.space }
{
	std::cout << "copy constructor" << std::endl;
	std::copy(a.elem, a.elem + a.sz, elem);
}

template <typename T>
RdVector<T>& RdVector<T>::operator=(const RdVector<T>& a)
{
	std::cout << "copy assignment" << std::endl;
	if (&a == this) return *this; // self-assignment, no work needed

	if (a.sz <= space) { // enough space, no need for new allocation
		for (size_t i = 0; i < a.sz; ++i) { // copy elements
			elem[i] = a.elem[i];
		}
		sz = a.sz;
		return *this;
	}
	T* p = new T[a.sz];
	std::copy(a.elem, a.elem + a.sz, p);
	delete[] elem;
	sz = a.sz;
	space = a.sz;
	elem = p;
	return *this;
}

template <typename T>
RdVector<T>::RdVector(RdVector&& a)
	: sz{ a.sz }, elem{ a.elem }, space{ a.space }
{
	std::cout << "move constructor" << std::endl;
	a.sz = 0;
	a.elem = nullptr;
}

template <typename T>
RdVector<T>& RdVector<T>::operator=(RdVector&& a)
{
	std::cout << "move assignment" << std::endl;
	//if (&a != this) {
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	space = a.space;
	a.elem = nullptr;
	a.sz = 0;
	a.space = 0;
	//}
	return *this;
}

template <typename T>
RdVector<T>::~RdVector()
{
	std::cout << "destructor" << std::endl;
	//if (elem) {
	delete[] elem;
	//}
}

template <typename T>
void RdVector<T>::reserve(size_t newalloc)
{
	if (newalloc <= space)
		return; // never decrease allocation

	T* p = new T[newalloc]; // allocate new space
	for (size_t i = 0; i < sz; ++i) {
		p[i] = elem[i]; // copy old elements
	}
	delete[] elem; // deallocate old space
	elem = p;
	space = newalloc;
}

// make the vector have newsize elements
// initialize each new element with the default value 0.0
template <typename T>
void RdVector<T>::resize(size_t newsize)
{
	reserve(newsize);
	for (size_t i = sz; i < newsize; ++i) {
		elem[i] = T{}; // initialize new elements
	}
	sz = newsize;
}

// increase vector size by one; initialize the new element with d
template <typename T>
void RdVector<T>::push_back(const T& d)
{
	if (space == 0) {
		reserve(8); // start with space for 8 elements
	}
	else if (sz == space) {
		reserve(2 * space); // get more space
	}
	elem[sz] = d; // add d at end
	++sz; // increase the size (sz is the number of elements)
}

#endif
