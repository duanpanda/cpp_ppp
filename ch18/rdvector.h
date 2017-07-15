#ifndef RDVECTOR_H
#define RDVECTOR_H
#pragma once
#include <initializer_list>

class RdVector
{
	size_t sz;
	double* elem;
public:
	RdVector() : sz{ 0 }, elem{ nullptr } {} // default constructor
	explicit RdVector(size_t s); // explicit one argument constructor
	explicit RdVector(std::initializer_list<double> lst); // initializer-list constructor
	RdVector(const RdVector&);                // copy constructor
	RdVector& operator=(const RdVector&);     // copy assignment
	RdVector(RdVector&& a);                   // move constructor
	RdVector& operator=(RdVector&&);          // move assignment
	~RdVector();
	double& operator[](int n) { return elem[n]; }      // for non-const vectors
	double operator[](int n) const { return elem[n]; } // for const vectors
};

#endif
