// keep all the values entered (converted into meters) in a vector, at the end,
// write out those values.

#include "../../std_lib_facilities.h"

double to_meter(double value, const string& unit)
{
  const double cm_per_m = 100;
  const double cm_per_in = 2.54;
  const double in_per_ft = 12;
  double a = value;

  if (unit == "m")
    ;                           // do nothing
  else if (unit == "in")
    a = value * cm_per_in / cm_per_m;
  else if (unit == "ft")
    a = value * in_per_ft * cm_per_in / cm_per_m;
  else if (unit == "cm")
    a = value / cm_per_m;
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
  double smallest = a;
  double largest = a;
  double sum = 0;
  vector<double> values;
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
    // now the input data are valid, keep on computing

    // echo the input in the original unit
    cout << a << unit;

    // convert to meters and store for comparation
    a = to_meter(a, unit);
    cout << " (" << a << "m)";

    values.push_back(a);

    // sum up
    sum += a;

    // comparation
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

  sort(values.begin(), values.end());

  // print the report
  cout << "Finally, smallest == " << smallest << "m"
       << ", largest == " << largest << "m"
       << ", number of values == " << values.size()
       << ", sum == " << sum << "m" << endl;
  cout << "The values in meter are:\n";
  for (int i = 0; i < values.size(); ++i) {
    cout << values[i] << ' ';
  }
  cout << endl;

  return 0;
}
