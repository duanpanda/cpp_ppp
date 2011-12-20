// while loop, read in a series of doubles and print them, '|' terminated.
// keep track of the smallest and the largest so far.

#include "../../std_lib_facilities.h"

int main()
{
  double a = 0;
  double smallest = a;
  double largest = a;
  bool first_input = true;

  while (cin >> a) {
    cout << a;        // Caution: the default print out pricision is not enough
    if (first_input) {
      smallest = a;
      largest = a;
      cout << ", the smallest so far";
      cout << ", the largest so far";
      first_input = false;
    }
    if (a < smallest) {
      smallest = a;
      cout << ", the smallest so far";
    }
    if (a > largest) {
      largest = a;
      cout << ", the largest so far";
    }
    cout << '\n';
  }

  return 0;
}
