// Drill 3
// Output a letter.
// Input: first_name, friend_name

#include "../../std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to, "
       << "and the name of a friend:\n";
  string first_name = "???";
  string friend_name = "???";
  cin >> first_name >> friend_name;
  cout << "Dear " << first_name << ",\n"
       << "    How are you? I am fine. I miss you. "
       << "Have you seen " << friend_name << " lately?\n"
       << "Yours sincerely,\n"
       << "    Ryan" << endl;
  return 0;
}
