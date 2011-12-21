// convert between spelled-out number and digit number

#include "../../std_lib_facilities.h"

bool is_digit(const string& s)
{
  return s == "0" or s == "1" or s == "2" or s == "3" or s == "4" or
    s == "5" or s == "6" or s == "7" or s == "8" or s == "9";
}

int is_spelled_num(const string& s, const vector<string>& dict)
{
  for (int i = 0; i < dict.size(); ++i) {
    if (s == dict[i])
      return i;
  }
  return -1;
}

int to_int(char c)
{
  return c - '0';
}

int main()
try
{
  vector<string> spelled_num(10);
  spelled_num[0] = "zero";
  spelled_num[1] = "one";
  spelled_num[2] = "two";
  spelled_num[3] = "three";
  spelled_num[4] = "four";
  spelled_num[5] = "five";
  spelled_num[6] = "six";
  spelled_num[7] = "seven";
  spelled_num[8] = "eight";
  spelled_num[9] = "nine";

  cout << "Please input a digit number or a spelled-out number, '|' to exit: ";
  string num = " ";
  int i = 0;
  while (cin >> num) {
    if (is_digit(num)) {
      i = to_int(num[0]);
      cout << num << " is " << spelled_num[i] << '\n';
    } else if ((i = is_spelled_num(num, spelled_num)) > -1) {
      cout << num << " is " << i << '\n';
    } else if (num == "|") {
      return 0;
    }else {
      cout << "bad number\n";
    }
    cout << "Try again, '|' to exit: ";
  }

  return 0;
}
catch (out_of_range& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (runtime_error& e) {
  cerr << "error: " << e.what() << '\n';
  return 2;
}
catch (...) {
  cerr << "unknown exception";
  return 3;
}
