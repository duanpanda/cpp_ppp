// while loop, read in two ints and print them, '|' terminated,
// output the smaller and the larger value

#include "../../std_lib_facilities.h"

int main()
{
  int a, b;
  while (cin >> a >> b) {
    cout << a << ' ' << b << '\n';
    if (a <= b) {
      cout << "the smaller value is: " << a << '\n'
           << "the larger value is: " << b << '\n';
    } else {
      cout << "the smaller value is: " << b << '\n'
           << "the larger value is: " << a << '\n';
    }
  }
  return 0;
}
