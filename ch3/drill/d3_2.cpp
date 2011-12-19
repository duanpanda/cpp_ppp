// Drill 2
// Output a letter.
// Input: first_name.

#include "../../std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to\n";
  string first_name = "???";
  cin >> first_name;
  cout << "Dear " << first_name << ",\n"
       << "    How are you? I am fine. I miss you.\n"
       << "Yours sincerely,\n"
       << "    Ryan" << endl;
  return 0;
}
