// standard input loop
#include "../std_lib_facilities.h"

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail()) { // use term as terminator and/or separator
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return; // all is fine
		error(message);
	}
}

int main()
{
	//ifstream ist{ "input.txt" };
	//for (int var; ist >> var; ) { // read until end of file
	//								  // maybe check that var is valid
	//								  // do something with var
	//}
	//if (ist.fail()) { // use '|' as terminator and/or separator
	//	ist.clear();
	//	char ch;
	//	if (!(ist >> ch && ch == '|')) error("bad termination of input");
	//}
	//// carry on: we found end of file or a terminator

	ifstream ist{ "input.txt" };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	for (int var; ist >> var; ) { // read until end of file
									  // maybe check that var is valid
									  // . . . do something with var . . .
	}
	end_of_loop(ist, '|', "bad termination of file"); // test if we can continue
													  // carry on: we found end of file or a terminator

	keep_window_open();
	return 0;
}
