#include "../std_lib_facilities.h"

struct X
{
	int val;
	void out(const string& s, int nv) {
		cerr << this << "->" << s << ": " << val << "(" << nv << ")\n";
	}

	X() {
		out("X()", 0);
		val = 0;
	}

	X(int v) {
		val = v;
		out("X(int)", v);
	}

	X(const X& x) {
		val = x.val;
		out("X(X&)", x.val);
	}

	X& operator=(const X& a) {
		out("X::operator=()", a.val);
		val = a.val;
		return *this;
	}

	~X() {
		out("~X()", 0);
	}
};

X glob(2); // a global variable
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
struct XX { X a; X b; };

inline void print_statement(string statement)
{
	cout << "\n\t" << statement << endl;
}

int main()
{
	print_statement("X loc{ 4 };");
	X loc{ 4 }; // local variable

	print_statement("X loc2{ loc };");
	X loc2{ loc }; // copy construction

	print_statement("loc = X{ 5 };");
	loc = X{ 5 }; // copy assignment

	print_statement("loc2 = copy(loc);");
	loc2 = copy(loc); // call by value and return

	print_statement("loc2 = copy2(loc);");
	loc2 = copy2(loc);

	print_statement("X loc3{ 6 };");
	X loc3{ 6 };

	print_statement("X& r = ref_to(loc);");
	X& r = ref_to(loc); // call by reference and return

	print_statement("delete make(7);");
	delete make(7);

	print_statement("delete make(8);");
	delete make(8);

	print_statement("vector<X> v(4);");
	vector<X> v(4); // default values

	print_statement("XX loc4;");
	XX loc4;

	print_statement("X* p = new X{ 9 };");
	X* p = new X{ 9 }; // an X on the free store

	print_statement("delete p;");
	delete p;

	print_statement("X* pp = new X[5];");
	X* pp = new X[5]; // an array of Xs on the free store

	print_statement("delete[] pp;");
	delete[] pp;

	keep_window_open();
}
