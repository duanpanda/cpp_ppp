#include "rdvector.h"
#include <algorithm>
#include <iostream>

RdVector::RdVector(size_t s)
	: sz{ s }, elem{ new double[s] } // uninitialized memory for elements
{
	for (size_t i = 0; i < sz; ++i) elem[i] = 0; // initialize
}

RdVector::RdVector(std::initializer_list<double> lst)
	: sz{ lst.size() }, elem{ new double[sz] } // uninitialized memory
{
	std::copy(lst.begin(), lst.end(), elem);
}

RdVector::RdVector(const RdVector& a)
	: sz{ a.sz }, elem{ new double[sz] }
{
	std::cout << "copy constructor" << std::endl;
	std::copy(a.elem, a.elem + a.sz, elem);
}

RdVector& RdVector::operator=(const RdVector& a)
{
	std::cout << "copy assignment" << std::endl;
	if (&a != this) {
		double* p = new double[a.sz];
		std::copy(a.elem, a.elem + a.sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
	}
	return *this;
}

RdVector::RdVector(RdVector&& a)
	: sz(a.sz), elem{ a.elem }
{
	std::cout << "move constructor" << std::endl;
	a.sz = 0;
	a.elem = nullptr;
}

RdVector& RdVector::operator=(RdVector&& a)
{
	std::cout << "move assignment" << std::endl;
	//if (&a != this) {
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	//}
	return *this;
}

RdVector::~RdVector()
{
	std::cout << "destructor" << std::endl;
	//if (elem) {
	delete[] elem;
	//}
}

std::ostream& operator<<(std::ostream& os, const RdVector& v)
{
	os << '[';
	for (size_t i = 0; i < v.size(); ++i) {
		os << ' ' << v[i];
	}
	os << " ]\n";
	return os;
}