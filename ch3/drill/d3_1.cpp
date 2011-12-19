// Drill 1
// Input first name, output "Dear first_name,".

#include "../../std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to\n";
  string first_name = "???";
  cin >> first_name;
  cout << "Dear " << first_name << ",\n";
  return 0;
}
