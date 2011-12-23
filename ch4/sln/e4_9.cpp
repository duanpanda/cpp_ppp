// Solve sigma(2^(i-1)) (i from 1 to x) = 1,000, or 1,000,000 or 1,000,000,000,
// compute x.
// Exercise 9: when x is 64, calculate sigma(2^(i-1)) (i = 1 to x).

#include "../../std_lib_facilities.h"

int main()
try
{
  cout << "First square contains one grain of rice, second square contains 2 grains, 4 for third, 8 for fourth, and so on, doubling for each of the 64 squares.\nHow many grains are there in all the 64 squares?\n\n";

  cout << "Let's see what is the largest number of squares for which we can calculate the exact number of grains using an int.\n\n";
  int i,term,sum;
  for (i=2,term=1,sum=1; i<=64; ++i) {
    term *= 2;
    sum += term;
    cout << "i=" << i << ",term=" << term << ",sum=" << sum << endl;
  }

  cout << "\nLet's see what is the largest number of squares for which we can calculate the exact number of grains using a double.\n\n";
  double dterm,dsum;
  for (i=2,dterm=1.0,dsum=1.0; i<=64; ++i) {
    dterm *= 2;
    dsum += dterm;
    cout << "i=" << i << ",term=" << dterm << ",sum=" << dsum << endl;
  }

  cout << "\nLet's see what is the largest number of squares for which we can calculate the exact number of grains using a long long int.\n\n";
  long long lterm,lsum;
  for (i=2,lterm=1,lsum=1; i<=64; ++i) {
    lterm *= 2;
    lsum += lterm;
    cout << "i=" << i << ",term=" << lterm << ",sum=" << lsum << endl;
  }

  cout << "\nThere are " << sum << " grains in all the 64 squares.  Of course, wrong!\n";

  return 0;
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "exiting\n";
  return 2;
}
