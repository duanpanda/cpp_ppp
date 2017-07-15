#include "../std_lib_facilities.h"
#include "rdvector.h"

void ff(const RdVector& cv, RdVector& v)
{
	double d = cv[1];
	//cv[1] = 2.0; // error (uses the const [])
	double d1 = v[1];
	v[1] = 2.0;
}

int main()
{
	RdVector v(10);
	double x = v[2];
	cout << x << endl;
	v[3] = x;
	cout << v[3] << endl;

	ff(v, RdVector{ 1, 2, 3, 4 });

	int a[20]{ 0 };
	a[-3] = 80; // huh? dangerous
	a[100] = 90; // huh? dangerous

	keep_window_open();
}