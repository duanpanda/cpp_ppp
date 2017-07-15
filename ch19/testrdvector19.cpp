#include "../std_lib_facilities.h"
#include "rdvector.h"

int main()
{
	RdVector<int> v { 1, 2, 3, 4 };
	cout << v;
	v.resize(0);
	cout << v << v.capacity() << endl;
	//v.resize(-77); // ouch! std::bad_array_new_length
	//cout << v;

	RdVector<RdVector<int> > vv(3);
	RdVector<int> a{ 1, 2, 3 };
	RdVector<int> b{ 4, 5 };
	RdVector<int> c{ 6, 7, 8, 9 };
	vv.push_back(a);
	vv.push_back(b);
	vv.push_back(c);
	cout << "vv.size()=" << vv.size() << endl;
	cout << vv[vv.size()-1][0] << endl;
	vv[0] = a;
	vv[1] = b;
	vv[2] = c;
	cout << vv[1][0] << endl;

	keep_window_open();
	return 0;
}