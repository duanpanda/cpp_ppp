// type safety
#include "../../std_lib_facilities.h"

int main()
{
  // variables are used without initial value
  double x;
  double y = x;
  double z = 2.0 + x;
  cout << x << ' ' << y << ' ' << z << endl;

  // safe conversion: char-to-int
  char c = 'x';
  int i1 = c;
  int i2 = 'x';
  char c2 = i1;
  cout << c << ' ' << i1 << ' ' << c2 << endl;

  // safe conversion: int-to-double
  double d1 = 2.3;
  double d2 = d1 + 2;           // 2 is converted to 2.0 before adding
  if (d1 < 0)                   // 0 is converted to 0.0 before comparison
    error("d1 is negative");

  // error("d1 is negative") prints this on my Debian GNU/Linux with gcc 4.4:
  // 
  //   terminate called after throwing an instance of 'std::runtime_error'
  //     what():  d1 is negative
  //   Aborted

  // unsafe conversions
  //   1. narrowing conversion
  {
    int a = 20000;
    char c = a;                 // try to squeeze a large int into a small char
    int b = c;
    if (a != b)
      cout << "oops!: " << a << " != " << b << '\n';
    else
      cout << "Wow! We have large characters\n";
  }

  double d = 0;
  while (cin >> d) {
    int i = d;                  // try to squeeze a double into an int
    char c = i;                 // try to squeeze an int into a char
    int i2 = c;                 // get the integer value of the character
    cout << "d==" << d              // the original double
         << " i==" << i             // converted to int
         << " i2==" << i2           // int value of char
         << " char(" << c << ")\n"; // the char
  }

  return 0;
}
