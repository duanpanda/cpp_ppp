// Read a vector of doubles.  Think of each value as the distance between two
// cities along a given route.  Compute and print the total distance.  Find and
// print the smallest, the greatest and the mean.

#include "../../std_lib_facilities.h"

// Caution: what if no input?
int main()
{
  vector<double> distances;
  double value;
  double sum = 0;
  double min = 0;
  double max = 0;
  double mean = 0;

  while (cin >> value) {
    distances.push_back(value);
  }

  sort(distances.begin(), distances.end());

  int i;
  for (i = 0; i < distances.size(); ++i)
    sum += distances[i];

  mean = sum / distances.size();

  cout << "total distance: " << sum << '\n'
       << "min: " << distances[0] << '\n'
       << "max: " << distances[distances.size() - 1] << '\n'
       << "mean: " << mean << '\n';

  return 0;
}
