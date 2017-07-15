#include "rdvector.h"
#include <algorithm>

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

RdVector::RdVector(const RdVector & a)
	: sz{ a.sz }, elem{ new double[sz] }
{
	std::copy(a.elem, a.elem + a.sz, elem);
}

RdVector& RdVector::operator=(const RdVector& a)
{
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
	a.sz = 0;
	a.elem = nullptr;
}

RdVector& RdVector::operator=(RdVector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

RdVector::~RdVector()
{
	delete[] elem;
}
