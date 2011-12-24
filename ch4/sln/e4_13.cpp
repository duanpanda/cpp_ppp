// find primes between 1 and 100
// using the classic "Sieve of Eratosthens" method

#include "../../std_lib_facilities.h"

// Strange:
//    For vector<bool> a, a[i] causes compile error:
//
// invalid initialization of non-const reference of type 'bool&' from a
// temporary of type 'std::_Bit_reference'.
//
//    So I have to use a.at(i) instead.

int main()
try
{
  const int max = 100;
  vector<bool> judges(max+1, true);

  for (int i=2; i<=max/2; ++i) {
    if (judges.at(i)) {
      for (int j=2*i; j<=max; j+=i)
        judges.at(j) = false;
    }
  }

  // now all k such that judges[k] is true are prime
  for (int k=2,cnt=0; k<judges.size(); ++k) {
    if (judges.at(k)) {
      cout << k;
      ++cnt;
      if (cnt%8==0)
        cout << '\n';
      else
        cout << '\t';
    }
  }

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
