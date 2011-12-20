/* Improve the method to compute the median.

   Define median as "the number for which exactly half of the elements of the
   sequence come before it and exactly half come after it".

   Idea:
   For even sequence (contains even number of elements), take the average
   of the two middle element as the median;
   for odd sequence, simply take the middle element.
*/

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
  int size = temps.size();
  int middle_index = size / 2;
  double median = 0;
  if (size % 2 == 0) {          // even
    median = (temps[middle_index-1] + temps[middle_index])/2;
  } else {                      // odd
    median = temps[middle_index];
  }
  cout << "Median temperature: " << median << endl;

  return 0;
}
