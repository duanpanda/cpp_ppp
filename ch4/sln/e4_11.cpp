// find all the primes between 1 and 100

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

  for (int i=3; i<=100; ++i)
    if (is_prime(i))
      primes.push_back(i);

  cout << "Primes between 1 and 100 are:\n";
  for (int j=0; j<primes.size(); ++j) {
    cout << primes[j];
    if (j%8==7)
      cout << '\n';
    else
      cout << '\t';
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
