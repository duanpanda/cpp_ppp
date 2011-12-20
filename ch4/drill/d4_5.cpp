// while loop, read in two doubles and print them, '|' terminated
// check the smaller, the larger, equality and almost equal.

#include "../../std_lib_facilities.h"

int main()
{
  double a, b;
  const double epsilon = 1.0/10000000;

  while (cin >> a >> b) {
    cout << a << ' ' << b << '\n';
    double diff = a - b;
    if (diff < 0) {
      cout << "the smaller value is: " << a << '\n'
           << "the larger value is: " << b << '\n';
      if (diff > -epsilon) {
        cout << "the numbers are almost equal\n";
      }
    } else if (diff > 0) {
      cout << "the smaller value is: " << b << '\n'
           << "the larger value is: " << a << '\n';
      if (diff < epsilon) {
        cout << "the numbers are almost equal\n";
      }
    } else {
      cout << "the numbers are equal\n";
    }
  }

  return 0;
}
