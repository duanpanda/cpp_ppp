// find the mode of a set of positive integers.
// mode is the number that appears most times

/*
 Advanced solution that I don't use now:
 1. make use of std::map.

 But I use struct and vector in case of sorting.
*/

#include "../../std_lib_facilities.h"

struct Entry
{
  string str;
  int cnt;

  Entry(string s, int c) :str(s), cnt(c) {}
};

int main()
try
{
  // input and make a map
  vector<Entry> seq;
  cout << "Please enter a sequence of strings, separated with whitespaces (newline, space or tab), end with \"|\" and newline:\n";
  string a;
  string min;
  string max;
  int i = 0;
  while (cin>>a) {
    if (a=="|") break;          // end of input

    if (seq.size()==0) {        // first string
      // create a new entry for the first string
      Entry t(a, 1);
      seq.push_back(t);
      min = a;
      max = a;
    } else {            // for other strings
      // keep track of min and max
      if (a<min)
        min = a;
      if (a>max)
        max = a;

      // first look up in seq, if found, increase its counter
      for (i=0; i<seq.size(); ++i) {
        if (seq[i].str==a) {
          ++seq[i].cnt;
          break;
        }
      }
      // if not found in seq, create a new entry
      if (i>=seq.size()) {
        Entry t(a, 1);
        seq.push_back(t);
      }
    }
  }

  // if no valid strings, simply return
  if (seq.size()==0)
    return 0;

  // extract the modes (there may be more than one modes.)
  int maxcnt = -1;                 // init an small enough value
  // only after scanning all times elements can we get the correct maxcnt.
  for (i=0; i<seq.size(); ++i) {
    if (seq[i].cnt>maxcnt) {
      maxcnt = seq[i].cnt;
    }
  }
  // now scan a second pass for all the elements that are maxcnt
  vector<string> modes;
  for (i=0; i<seq.size(); ++i) {
    if (seq[i].cnt==maxcnt) {
      modes.push_back(seq[i].str);
    }
  }

  // output
  //   min and max
  cout << "min is " << min << '\n';
  cout << "max is " << max << '\n';
  //   modes
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
