#include "../../std_lib_facilities.h"

// Compare 3 times for 3 elements.
int main()
{
  int a, b, c;
  cout << "Please enter 3 integers:\n";
  cin >> a >> b >> c;

  int t = a;

  // swap to assure a <= b
  if (a > b) {
    // swap
    t = a;
    a = b;
    b = t;
  }

  // compare c with a, and compare c with b
  if (c <= a)
    cout << c << ',' << a << ',' << b << endl;
  else if (c >= b)
    cout << a << ',' << b << ',' << c << endl;
  else                          // c > a && c < b
    cout << a << ',' << c << ',' << b << endl;

  return 0;
}
