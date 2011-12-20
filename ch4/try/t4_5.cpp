// function
#include "../../std_lib_facilities.h"

int square(int x)
{
  int n = 0;
  for (int i = 0; i < x; ++i)
    n += x;
  return n;
}

int main()
{
  int x;
  cout << "Please input an integer:\n";
  cin >> x;
  cout << "square(" << x << ")==" << square(x) << endl;
  return 0;
}
