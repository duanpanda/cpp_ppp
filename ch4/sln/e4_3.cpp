// Read a vector of doubles.  Think of each value as the distance between two
// cities along a given route.  Compute and print the total distance.  Find and
// print the smallest, the greatest and the mean.

#include "../../std_lib_facilities.h"

/*
	Immediately, we are faced with the question "when do we stop reading in distance values?
	My choice here is "whenever we find a 0 or a negative distance"

	I decided to compute the sum of the distances, the smallest distance, and the largest distance
	as we read along. I could have waited until every value had been read and then go through the
	read values (now stored in the vector dist).
*/

int main()
try
{
  vector<double> dist;

  double sum = 0;               // accumulate total distance in sum
  double min = 0;               // smallest distance
  double max = 0;               // largest distance

  cout << "Please enter whitespace-separated sequence of doubles (representing distances) :";
  double val;
  while (cin >> val) {
    if (val <= 0) {
      if (dist.size() == 0) error("no distances");
      cout << "total distance " << sum << '\n';
      cout << "smallest distance " << min << '\n';
      cout << "greatest distance " << max << '\n';
      cout << "mean distance " << sum / dist.size() << '\n';
      keep_window_open("~");
      return 0;
    }
    dist.push_back(val);

    // update the "running" values:
    sum += val;
    if (val < min) min = val;
    if (max < val) max = val;
  }

  if (dist.size() == 0) error("no distances");
  cout << "total distance " << sum << '\n'
       << "smallest distance " << min << '\n'
       << "greatest distance " << max << '\n'
       << "mean distance " << sum / dist.size() << '\n';
  keep_window_open("~");
}
catch (runtime_error e) {
  cout << e.what() << '\n';
  keep_window_open("~");        // for some Windows(tm) setups
}
catch (...) {
  cout << "exiting\n";
  keep_window_open("~");
}
