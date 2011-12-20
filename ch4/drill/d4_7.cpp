// Add units: cm , m, in, ft.

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
    a = value * in_per_ft *cm_per_in;
  else if (unit == "cm")
    ;                           // do nothing
  else
    error("unknown unit");

  return a;
}

int main()
{
  double a = 0;
  string unit = " ";            // not a unit

  double smallest = a;          // cm
  double largest = a;           // cm
  bool first_input = true;

  while (cin >> a >> unit) {
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
