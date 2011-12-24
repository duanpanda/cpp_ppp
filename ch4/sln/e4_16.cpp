// find the mode of a set of positive integers.
// mode is the number that appears most times

/*
 Advanced solutions that I don't use now:
 1. make use of std::map.
 2. make use of struct and vector.
*/

#include "../../std_lib_facilities.h"

int main()
try
{
  // input and make a map using nums and times
  vector<int> nums;
  vector<int> times;
  cout << "Please enter a sequence of positive integers, end with '|':\n";
  int a = 0;
  int i = 0;
  while (cin>>a) {
    if (a<=0) error("non-positive or bad input");

    if (nums.size()==0) {       // first number
      // create a new entry for the first number
      nums.push_back(a);
      times.push_back(1);
    } else {           // for other numbers
      // first look up in nums, if found, increase its counter
      for (i=0; i<nums.size(); ++i) {
        if (nums[i]==a) {
          ++times[i];
          break;
        }
      }
      // if not found in nums, create a new entry
      if (i>=nums.size()) {
        nums.push_back(a);
        times.push_back(1);
      }
    }
  }

  // now nums.size() must equal to times.size()

  // if no valid numbers, simply return
  if (nums.size()==0)
    return 0;

  // extract the modes (note: maybe times[i]==times[j], so there may be more
  // than one modes.)
  int max = -1;                 // init an small enough value
  // only after scanning all times elements can we get the correct max.
  for (i=0; i<times.size(); ++i) {
    if (times[i]>max) {
      max = times[i];
    }
  }
  // now scan a second pass for all the elements that are max
  vector<int> modes;
  for (i=0; i<times.size(); ++i) {
    if (times[i]==max) {
      modes.push_back(nums[i]);
    }
  }

  // output
  int s = modes.size();
  string desc;
  if (s==1) {
    desc = "mode is ";
  } else {
    desc = "modes are ";
  }
  cout << "The " << desc;
  for (i=0; i<s-1; ++i) {
    cout << modes[i] << ", ";
  }
  cout << modes[i] << ".\n";

  return 0;
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "exiting\n";
  return 2;
}
