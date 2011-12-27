// run-time errors

#include "../../std_lib_facilities.h"

int area(int length, int width)
{
  if (length<=0 || width<=0) return -1;
  return length*width;
}

int framed_area(int x, int y)
{
  return area(x-2, y-2);
}

int f(int x, int y, int z)
{
  int area1 = area(x, y);
  if (area1<=0) error("non-positive area");
  // !!!
  // forget to test the return value of area()
  // !!!
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1)/area3; // convert to double to get
                                      // floating-point division
  //...
}

int main()
{
  // int x = -1;
  // int y = 2;
  // int z = 4;
  // ...
  // cout << f(x, y, z) << endl;

  int x, y, z;
  // We can set x,y,z to let area2 and area3 in f() be negative or zero
  // to catch the errors in f().
  while (cin >> x >> y >> z) {
    cout << f(x, y, z) << endl;
  }
}
