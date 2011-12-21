// a simple calculator: accept just single-digit numbers written as either
// digits or spelled out.

#include "../../std_lib_facilities.h"

// global data
vector<string> g_numbers;

void init_num_dict()
{
  g_numbers.push_back("zero");
  g_numbers.push_back("one");
  g_numbers.push_back("two");
  g_numbers.push_back("three");
  g_numbers.push_back("four");
  g_numbers.push_back("five");
  g_numbers.push_back("six");
  g_numbers.push_back("seven");
  g_numbers.push_back("eight");
  g_numbers.push_back("nine");
}

bool is_digit(const string& s)
{
  return (s.size() == 1) && s[0] >= '0' && s[0] <= '9';
}

// Return the corresponding digit value, or -1 to indicate not-found.
int is_spelled_num(const string& s)
{
  for (int i = 0; i < g_numbers.size(); ++i) {
    if (s == g_numbers[i])
      return i;
  }
  return -1;
}

inline int to_int(char c)
{
  return c - '0';
}

int get_num()
{
  int val = 0;
  string s = " ";
  cin >> s;
  if (is_digit(s)) {
    return val = to_int(s[0]);
  } else if ((val = is_spelled_num(s)) > -1) {
    return val;
  } else {
    error("bad number");
  }
}

int main()
try
{
  cout << "You can input two single-digit numbers as the operands written as either digits or spelled out, e.g., \"0\" or \"zero\", \"1\" or \"one\", \"9\" or \"nine\"then you input an operator (+,-,*,/,%) to do the calculation.\n";

  init_num_dict();

  while (true) {
    cout << "Input the first operand: ";
    int a = get_num();

    cout << "Input the second operand: ";
    int b = get_num();

    cout << "Input the operator: ";
    char op = 0;
    cin >> op;

    string oper = " ";
    int res = 0;
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
    case '%':
      if (b == 0) error("trying to divide by zero (%)");
      oper = "The remainder of ";
      res = a % b;
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
