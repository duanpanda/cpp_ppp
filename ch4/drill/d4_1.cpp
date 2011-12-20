// while loop, read in two ints and print them, '|' terminated

#include "../../std_lib_facilities.h"

int main()
{
  int a, b;
  while (cin >> a >> b) {
    cout << a << ' ' << b << '\n';
  }
  return 0;
}
