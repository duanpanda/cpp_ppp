// find primes between 1 and max
// using the classic "Sieve of Eratosthens" method

#include "../../std_lib_facilities.h"

int main()
try
{
  cout << "Please enter an integer larger than 2, '|' to quit: ";
  int max;
  while (cin>>max) {
    if (max <= 2) {
      cout << "max is not larger than 2.\n"
           << "Please enter an integer larger than 2, '|' to quit: ";
      continue;
    }

    vector<int> judges(max+1, 1);
    for (int i=2; i<=max/2; ++i) {
      if (judges.at(i)) {
        for (int j=2*i; j<=max; j+=i)
          judges.at(j) = 0;
      }
    }

    // now all k such that judges[k] is true are prime
    vector<int> primes;
    for (int k=2; k<judges.size(); ++k) {
      if (judges.at(k))
        primes.push_back(k);
    }

    cout << "Primes between 1 and " << max << " are:\n";
    for (int k=0; k<primes.size(); ++k) {
      cout << primes[k];
      if (k==primes.size()-1 || k%8==7)
        cout << '\n';
      else
        cout << '\t';
    }

    // re-initialization
    cout << "Try again, '|' to quit: ";
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
