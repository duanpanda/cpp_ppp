// Solve sigma(2^(i-1)) (i from 1 to x) = 1,000, or 1,000,000 or 1,000,000,000,
// compute x.

#include "../../std_lib_facilities.h"

// Pre: goal >= 0
int solve(int goal)
{
  if (goal < 0) error("bad argument for solve()");

  if (goal == 0)
    return 0;
  else if (goal == 1)
    return 1;

  // e.g.
  // i=0 term=0 sum=0
  // i=1 term=1 sum=1
  // i=2 term=2 sum=3
  // i=3 term=4 sum=7
  // i=4 term=8 sum=15
  // ...
  int i, term, sum;
  for (i=2,term=1,sum=1; sum<goal; ++i) {
    term *= 2;
    sum += term;
    cerr << "i=" << i << ",term=" << term << ",sum=" << sum << endl;
  }
  return i-1;
}

int main()
try
{
  cout << "First square contains one grain of rice, second square contains 2 grains, 4 for third, 8 for fourth, and so on, doubling for each of the 64 squares.\nHow many squares are required to give at least 1,000 grains of rice, at least 1,000,000 grains, at least 1,000,000,000 grains?\n\n";

  const int goal_1 = 1000;
  const int goal_2 = 1000000;
  const int goal_3 = 1000000000;

  int squares = solve(goal_1);
  cout << squares << " is needed to provide at least " << goal_1 << " grains.\n";

  squares = solve(goal_2);
  cout << squares << " is needed to provide at least " << goal_2 << " grains.\n";

  squares = solve(goal_3);
  cout << squares << " is needed to provide at least " << goal_3 << " grains.\n";

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
