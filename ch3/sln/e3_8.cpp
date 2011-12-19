#include "../../std_lib_facilities.h"

int main()
{
  int a;
  cout << "Please input an integer:\n";
  cin >> a;
  if (a % 2 == 0)
    cout << "The value " << a << " is an even number.\n";
  else
    cout << "The value " << a << " is an odd number.\n";

  return 0;
}
