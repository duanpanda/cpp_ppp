#include "../std_lib_facilities.h"
#include "rdvector.h"

RdVector foo(const RdVector& a)
{
	return a;
}

int main()
{
	// test default constructor
	RdVector va;
	// test output operator
	cout << va;

	// test one argument constructor
	RdVector vb(10);
	cout << vb;

	// test explicit
	// if we remove "explicit" on the constructors, the following two lines can compile
	//
	//RdVector vc = 20; // no suitable constructor exists to convert from "int" to "RdVector"
	//RdVector vc = std::initializer_list<double>{ 1, 2, 3, 4 }; // no suitable constructor exists to convert
	//cout << vc;

	// test initializer-list constructor
	RdVector vd{ 1, 2, 3, 4, 5 };
	cout << vd;

	// test copy constructor
	RdVector ve{ vd };
	cout << ve;

	// test copy assignment
	ve = va;
	cout << ve;

	// test move constructor
	// Create a vector object and add a few elements to it.  
	vector<RdVector> vf;
	vf.push_back(RdVector(25));
	vf.push_back(RdVector(75));
	// Insert a new element into the second position of the vector.  
	vf.insert(vf.begin() + 1, RdVector(50));
	cout << vf[0] << vf[1] << vf[2] << endl;

	// test move assignment
	RdVector vg;
	cout << vg;
	vg = foo(vd); // move assignment
	cout << vg;
	vg = vf[1]; // copy assignment
	cout << vg << endl;

	// test subscript
	vb[1] = 1000;
	vb[3] = vd[2];
	cout << vb;

	keep_window_open();
	return 0;
}