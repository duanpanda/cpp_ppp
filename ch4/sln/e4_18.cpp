// solve the quadratic equation ax^2+bx+c=0

#include "../../std_lib_facilities.h"

int main()
try
{
  cout << "Please input the coefficients a, b, and c, of the quadratic equation ax^2+bx+c=0, separated with whitespaces, enter 'q' or non-number to quit :\n";
  double a = 0;
  double b = 0;
  double c = 0;
  while (cin>>a>>b>>c) {
    if (a==0) {
      cout << "a==0, the equation degrades to linear: bx+c=0\n";
      double x;
      x = -c/b;
      cout << "x==" << x << endl;
    } else {
      double delta = b*b-4*a*c;
      if (delta>0) {
        double x1 = 0;
        double x2 = 0;
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        cout << "x1==" << x1 << ", " << "x2==" << x2 << endl;
      } else if (delta==0) {
        double x;
        x = -b / (2*a);
        cout << "Only one root, x==" << x << endl;
      } else {
        cout << "delta==b*b-4*a*c==" << delta << " < 0, the equation has no root.\n";
      }
    }

    cout << "Try again, enter 'q' to quit:\n";
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
