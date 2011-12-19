#include "../../std_lib_facilities.h"

int main()
{
  int val1;
  int val2;
  
  cout << "Please enter two integers:\n";
  cin >> val1 >> val2;

  if (val1 < val2) {
    cout << "The smallest is " << val1 << '\n';
    cout << "The largest is " << val2 << '\n';
  } else {
    cout << "The smallest is " << val2 << '\n';
    cout << "The largest is " << val1 << '\n';
  }

  cout << "The sum is " << val1 + val2 << '\n';
  cout << "The difference (" << val1 << '-' << val2 << ") is " << val1 - val2 << '\n';
  cout << "The product is " << val1 * val2 << '\n';
  cout << "The ratio (" << val1 << '/' << val2 << ") is " << val1 / val2 << '\n';
  
  return 0;
}
