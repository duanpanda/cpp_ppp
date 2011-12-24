// find primes between 1 and max

#include "../../std_lib_facilities.h"

vector<int> primes;

bool is_prime(int n)
{
  for (int i=0; i<primes.size(); ++i)
    if (n%primes[i]==0) return false;
  return true;
}

int main()
try
{
  primes.push_back(2);

  cout << "Please enter an integer larger than 2, '|' to quit: ";
  int max;
  while (cin>>max) {
    if (max <= 2) {
      cout << "max is not larger than 2.\n"
           << "Please enter an integer larger than 2, '|' to quit: ";
      continue;
    }

    for (int i=3; i<=max; ++i)
      if (is_prime(i))
        primes.push_back(i);

    cout << "Primes between 1 and " << max << " are:\n";
    for (int j=0; j<primes.size(); ++j) {
      cout << primes[j];
      if (j==primes.size()-1 || j%8==7)
        cout << '\n';
      else
        cout << '\t';
    }

    // re-initialize and prompt to try again
    primes.clear();             // global data headache
    primes.push_back(2);
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
