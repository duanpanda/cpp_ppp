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
    string oper = " ";
    double res = 0;
    switch (op) {
    case '+':
      oper = "The sum of ";
      res = a + b;
      break;
    case '-':
      oper = "The difference of ";
      res = a - b;
      break;
    case '*':
      oper = "The product of ";
      res = a * b;
      break;
    case '/':
      if (b == 0) error("trying to divide by zero");
      oper = "The ratio of ";
      res = a / b;
      break;
    default:
      error("unkown operator");
      break;
    }

    cout << oper << a << " and " << b << " is " << res << endl;
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
