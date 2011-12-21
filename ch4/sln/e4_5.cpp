// a simple calculator

// Note: It is similar to exercise 3.10.

#include "../../std_lib_facilities.h"

int main()
try
{
  char op = 0;
  double a = 0;
  double b = 0;

  cout << "Please enter two floating-point values separated by an operator (+,-,*,/):\n";
  while (cin >> a >> op >> b) {
    double res = 0;
    switch (op) {
    case '+':
      res = a + b;
      break;
    case '-':
      res = a - b;
      break;
    case '*':
      res = a * b;
      break;
    case '/':
      if (b == 0) error("trying to devide by zero");
      res = a / b;
      break;
    default:
      error("unkown operator");
      break;
    }

    cout << a << ' ' << op << ' ' << b << " == " << res << endl;
    cout << "Try again:\n";
  }
}
catch (runtime_error e) {
  cout << e.what() << '\n';
  keep_window_open("~");
}
catch (...) {
  cout << "exiting\n";
  keep_window_open("~");
}
