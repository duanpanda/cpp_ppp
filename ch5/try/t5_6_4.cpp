// 5.6 Exceptions
//   5.6.4 Narrowing errors

#include "../../std_lib_facilities.h"

int main()
try
{
  int x1 = narrow_cast<int>(2.9);    // throws
  int x2 = narrow_cast<int>(2.0);    // OK
  char c1 = narrow_cast<char>(1066); // throws
  char c2 = narrow_cast<char>(85);   // OK
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
