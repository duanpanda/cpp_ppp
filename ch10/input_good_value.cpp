// input a single acceptable value
#include "../std_lib_facilities.h"

void skip_to_int()
{
	if (cin.fail()) { // we found something that wasn’t an integer
		cin.clear(); // we’d like to look at the characters
		for (char ch; cin >> ch; ) { // throw away non-digits
			if (isdigit(ch) || ch == '-') {
				cin.unget(); // put the digit back,
							 // so that we can read the number
				return;
			}
		}
	}
	error("no input"); // eof or bad: give up
}

int get_int()
{
	int n = 0;
	while (true) {
		if (cin >> n) return n;
		cout << "Sorry, that was not a number; please try again\n";
		skip_to_int();
	}
}

int get_int(int low, int high)
{
	cout << "Please enter an integer in the range "
		<< low << " to " << high << " (inclusive):\n";
	while (true) {
		int n = get_int();
		if (low <= n && n <= high) return n;
		cout << "Sorry "
			<< n << " is not in the [" << low << ':' << high
			<< "] range; please try again\n";
	}
}

int get_int(int low, int high, const string& greeting, const string& sorry)
{
	cout << greeting << ": [" << low << ':' << high << "]\n";
	while (true) {
		int n = get_int();
		if (low <= n && n <= high) return n;
		cout << sorry << ": [" << low << ':' << high << "]\n";
	}
}

int main()
{
	///////////////////////////////////////////////////////////////////////////
	// solution 1
	// ugly, sort of work,
	// cannot handle 't' or "end of file" in which case n will have an
	// out-of-range value.
	///////////////////////////////////////////////////////////////////////////
	//cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
	//int n = 0;
	//while (cin >> n) { // read
	//	if (1 <= n && n <= 10) break; // check range
	//	cout << "Sorry "
	//		<< n << " is not in the [1:10] range; please try again\n";
	//}

	///////////////////////////////////////////////////////////////////////////////
	// To get a robust read, we must deal with three problems:
	//   1. The user typing an out-of-range value
	//   2. Getting no value (end of file)
	//   3. The user typing something of the wrong type (here, not an integer)
	//
	// There are 3 choices to handle them:
	//   1. Handle the problem in the code doing the read.
	//   2. Throw an exception to let someone else handle the problem (potentially terminating the program)
	//   3. Ignore the problem.
	//
	// solution 2
	//   Handling both an out-of-range input and an input of the wrong type locally.
	//---------------
	//cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
	//int n = 0;
	//while (true) {
	//	cin >> n;
	//	if (cin) { // we got an integer; now check it
	//		if (1 <= n && n <= 10) break;
	//		cout << "Sorry "
	//			<< n << " is not in the [1:10] range; please try again\n";
	//	}
	//	else if (cin.fail()) { // we found something that wasn’t an integer
	//		cin.clear(); // set the state back to good();
	//					 // we want to look at the characters
	//		cout << "Sorry, that was not a number; please try again\n";
	//		for (char ch; cin >> ch && !isdigit(ch); ) // throw away non-digits
	//			/* nothing */;
	//		if (!cin) error("no input"); // we didn’t find a digit: give up
	//		cin.unget(); // put the digit back, so that we can read the number
	//	}
	//	else {
	//		error("no input"); // eof or bad: give up
	//	}
	//}
	//// if we get here n is in [1:10]
	//cout << "n: " << n << '\n';
	//--------
	// The reason that the code is messy is that code dealing with several concerns is all
	// mixed together:
	//  * Reading values
	//  * Prompting the user for input
	//  * Writing error messages
	//  * Skipping past "bad" input characters
	//  * Testing the input against a range
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// Solution 3: skip_to_int() utility function
	///////////////////////////////////////////////////////////////////////////
	//cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
	//int n = 0;
	//while (true) {
	//	if (cin >> n) { // we got an integer; now check it
	//		if (1 <= n && n <= 10) break;
	//		cout << "Sorry " << n
	//			<< " is not in the [1:10] range; please try again\n";
	//	}
	//	else {
	//		cout << "Sorry, that was not a number; please try again\n";
	//		skip_to_int();
	//	}
	//}
	// if we get here n is in [1:10]

	///////////////////////////////////////////////////////////////////////////
	// Solution 4: get_int() functions
	///////////////////////////////////////////////////////////////////////////
	//int n = get_int(1, 10);
	//cout << "n: " << n << '\n';
	//int m = get_int(2, 300);
	//cout << "m: " << m << '\n';

	///////////////////////////////////////////////////////////////////////////
	// Solution 5: get_int() function with customized messages
	///////////////////////////////////////////////////////////////////////////
	int strength = get_int(1, 10, "enter strength", "Not in range, try again");
	cout << "strength: " << strength << '\n';
	int altitude = get_int(0, 50000,
		"Please enter altitude in feet",
		"Not in range, please try again");
	cout << "altitude: " << altitude << "f above sea level\n";

	keep_window_open();
	return 0;
}

