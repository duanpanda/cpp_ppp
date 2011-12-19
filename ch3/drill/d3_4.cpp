// Drill 4
// Output a letter.
// Input: first_name, friend_name, friend_sex.

#include "../../std_lib_facilities.h"

int main()
{
  string first_name = "???";
  string friend_name = "???";
  cout << "Enter the name of the person you want to write to, "
       << "and the name of a friend:\n";
  cin >> first_name >> friend_name;

  char friend_sex = 0;
  cout << "Please enter the sex of the friend, "
    "'f' for female and 'm' for male:\n";
  while (cin >> friend_sex &&
         friend_sex != 'm' && friend_sex != 'f') {
    cout << "Sex error. ";
    cout << "Please enter the sex of the friend, "
      "'f' for female and 'm' for male:\n";
  }

  cout << "Dear " << first_name << ",\n"
       << "    How are you? I am fine. I miss you. "
       << "Have you seen " << friend_name << " lately? ";
  if (friend_sex == 'm')
    cout << "If you see " << friend_name << " please ask him to call me.\n";
  else
    cout << "If you see " << friend_name << " please ask her to call me.\n";
    
  cout << "Yours sincerely,\n"
       << "    Ryan" << endl;

  return 0;
}
