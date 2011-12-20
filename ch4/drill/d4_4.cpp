// while loop, read in two doubles and print them, '|' terminated
// check the smaller, the larger and equality.

#include "../../std_lib_facilities.h"

int main()
{
  double a, b;
  while (cin >> a >> b) {
    cout << a << ' ' << b << '\n';
    if (a < b) {
      cout << "the smaller value is: " << a << '\n'
           << "the larger value is: " << b << '\n';
    } else if (a > b) {
      cout << "the smaller value is: " << b << '\n'
           << "the larger value is: " << a << '\n';
    } else {
      cout << "the numbers are equal\n";
    }
  }
  return 0;
}
