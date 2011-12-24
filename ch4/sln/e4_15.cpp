// find the first n primes, n gets from the user input.

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

  cout << "Please enter a positive integer, '|' to quit: ";
  int n;
  while (cin>>n) {
    if (n<=0) {
      cout << "n must be positive. Try again, '|' to quit: ";
      continue;
    }

    for (int i=3; primes.size()<n; ++i) {
      if (is_prime(i))
        primes.push_back(i);
    }

    cout << "The first n primes are:\n";
    for (int j=0; j<primes.size(); ++j) {
      cout << primes[j];
      if (j==primes.size()-1 || j%8==7)
        cout << '\n';
      else
        cout << '\t';
    }

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
