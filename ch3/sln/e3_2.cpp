#include "../../std_lib_facilities.h"

int main()
{
  const double kilometers_per_mile = 1.609;
  double x;
  cout << "Please enter the distance in mile:\n";
  cin >> x;
  cout << x << " miles == " << x * kilometers_per_mile << " kilometers.\n";
  
  return 0;
}
