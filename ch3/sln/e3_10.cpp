#include "../../std_lib_facilities.h"

int main()
{
  string op;
  double a = 0.0, b = 0.0;
  cout << "Please enter an operation followed by two numbers:\n";
  cin >> op >> a >> b;

  if (op == "+" || op == "plus")
    cout << a << "+" << b << "==" << a+b << endl;
  else if (op == "-" || op == "minus")
    cout << a << "-" << b << "==" << a-b << endl;
  else if (op == "*" || op == "mul")
    cout << a << "*" << b << "==" << a*b << endl;
  else if (op == "/" || op == "div")
    cout << a << "/" << b << "==" << a/b << endl;
  else
    cout << "unknown operation" << endl;

  return 0;
}
