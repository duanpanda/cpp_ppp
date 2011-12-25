// lines that are commented have compile-time errors
// lines with x4, x5 and x6 introduced non-errors

#include "../../std_lib_facilities.h"

int area(int length, int width)
{
  return length * width;
}

int main()
{
  //int s1 = area(7;
  //int s1 = area(7)
  //Int s3 = area(7);
  //int s4 = area('7);

  //int x0 = arena(7);
  //int x1 = area(7);
  //int x2 = area("seven", 2);

  int x4 = area(10, -7); // OK: but what is a rectangle with a width of minus 7?
  int x5 = area(10.7, 9.3);     // OK: but calls area(10,9)
  char x6 = area(100, 9999);    // OK, but truncates the result
  cout << "x4==" << x4 << ", x5==" << x5 << ", x6==" << (int)x6 << endl;
}
