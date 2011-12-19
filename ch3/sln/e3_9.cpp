#include "../../std_lib_facilities.h"

int main()
{
  string num;
  cout << "Please input a spell-out number, "
       << "one of \"zero\", \"one\", \"two\", \"three\" and \"four\".\n";
  cin >> num;

  if (num == "zero")
    cout << 0 << '\n';
  else if (num == "one")
    cout << 1 << '\n';
  else if (num == "two")
    cout << 2 << '\n';
  else if (num == "three")
    cout << 3 << '\n';
  else if (num == "four")
    cout << 4 << '\n';
  else
    cout << "not a number I know" << '\n';

  return 0;
}
