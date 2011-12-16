// simple program to exercise operators
#include "../../std_lib_facilities.h"

int main()
{
  cout << "Please enter an integer value: ";

  // We can try to input at least the following types of number to test:
  //     positive integer
  //     negative integer
  //     positive double-float
  //     negative double-float
  int n;
  cin >> n;

  cout << "n == " << n
       << "\nn+1 == " << n+1
       << "\nthree times n == " << 3*n
       << "\ntwice n == " << n+n
       << "\nn squared == " << n*n
       << "\nhalf of n == " << n/2
       << "\nsquare root of n == " << sqrt(n)
       << "\nn modulo 2 == " << n%2
       << "\nn/2 * 2 + n%2 == " << n/2*2+n%2
       << "\nn modulo -2 == " << n%(-2)
       << "\nn/(-2) * (-2) + n%(-2) == " << n/(-2)*(-2)+n%(-2)
       << endl;                 // another name of newline ("end of line")
  return 0;
}
