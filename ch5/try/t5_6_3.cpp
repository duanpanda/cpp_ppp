// 5.6 Exceptions
//   5.6.3 Bad input

#include "../../std_lib_facilities.h"

double some_function()
{
  double d = 0;
  cin >> d;
  if (!cin) error("couldn't read a double in 'some_function()'");
  // do something useful
}

int other_func()
{
}

int main()
try
{
  cout << some_function() << endl;
  cout << other_func() << endl;
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
