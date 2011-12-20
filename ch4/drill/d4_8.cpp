// Reject values without units or with "illegal" representations of units,
// such as y, yard, meter, km and gallons.

#include "../../std_lib_facilities.h"

double to_cm(double value, const string& unit)
{
  const double cm_per_m = 100;
  const double cm_per_in = 2.54;
  const double in_per_ft = 12;
  double a = value;

  if (unit == "m")
    a = value * cm_per_m;
  else if (unit == "in")
    a = value * cm_per_in;
  else if (unit == "ft")
    a = value * in_per_ft * cm_per_in;
  else if (unit == "cm")
    ;                           // do nothing
  else
    error("unknown unit");

  return a;
}

void print_prompt()
{
  cout << "Please input the value followed by unit (cm, m, in, ft):\n";
}

int main()
{
  double a = 0;
  double smallest = a;          // cm
  double largest = a;           // cm
  bool first_input = true;

  print_prompt();
  while (cin >> a) {
    string unit = " ";            // not a unit
    cin >> unit;

    // check the validity of the data
    if (unit == " ") {
      cout << "No unit inputted.\n";
      print_prompt();
      continue;
    }
    // not any of known units
    if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {
      cout << "unknown unit\n";
      print_prompt();
      continue;
    }

    cout << a << unit;

    // convert to cm and store for comparation
    a = to_cm(a, unit);
    cout << " (" << a << "cm)";

    if (first_input) {
      smallest = a;
      largest = a;
      cout << ", the smallest so far";
      cout << ", the largest so far";
      first_input = false;
    }
    if (a < smallest) {
      smallest = a;
      cout << ", the smallest so far";
    }
    if (a > largest) {
      largest = a;
      cout << ", the largest so far";
    }
    cout << '\n';
  }

  return 0;
}
