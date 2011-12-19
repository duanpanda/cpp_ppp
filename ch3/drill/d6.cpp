// Drill 6 and 7
// Output a letter.
// Input: first_name, friend_name, friend_sex, age.
// "If" on age.

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

  int age = 0;
  cout << "Please enter the age of the recipient:\n";
  cin >> age;
  if (age <= 0 || age >= 110)
    error("you're kidding!");

  cout << "Dear " << first_name << ",\n\n"
       << "    How are you? I am fine. I miss you. "
       << "Have you seen " << friend_name << " lately? ";
  if (friend_sex == 'm')
    cout << "If you see " << friend_name << " please ask him to call me. ";
  else
    cout << "If you see " << friend_name << " please ask her to call me. ";

  cout << "I hear you just had a birthday and you are " << age;
  if (age == 1)
    cout << " year old. ";
  else
    cout << " years old. ";

  if (age < 12)
    cout << "Next year you will be " << age + 1 << ".\n\n";
  else if (age == 17)
    cout << "Next year you will be able to vote.\n\n";
  else if (age > 70)
    cout << "I hope you are enjoying retirement.\n\n";
  else
    cout << "\n\n";

  cout << "Yours sincerely,\n\n\n"
       << "    Ryan" << endl;

  return 0;
}
