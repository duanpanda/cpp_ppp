// compute mean and median temperatures

#include "../../std_lib_facilities.h"

int main()
{
  vector<double> temps;         // temperatures
  double temp;
  while (cin >> temp)           // read
    temps.push_back(temp);      // put into vector

  // compute mean temperature
  double sum = 0;
  for (int i = 0; i < temps.size(); ++i)
    sum += temps[i];
  cout << "Average temperature: " << sum/temps.size() << endl;

  // compute median temperature
  sort(temps.begin(), temps.end()); // sort temps
                                    // "from the beginning to the end"
  cout << "Median temperature: " << temps[temps.size()/2] << endl;

  return 0;
}
