// name-and-value pairs

#include "../../std_lib_facilities.h"

// Return the index of the name found in v; return -1 if not found.
int find_name(const vector<string>& v, const string& name)
{
  for (int i=0; i<v.size(); ++i) {
    if (v[i]==name)
      return i;
  }
  return -1;
}

int main()
try
{
  cout << "Please input several name-score pairs, such as \"Joe 17\" and \"Barbara 22\", one pair for one line, name and score are separated with whitespaces.  At last, enter \"No more\" to terminate the input.\n";
  vector<string> names;
  vector<int> scores;
  string n;
  int s = 0;
  while (cin >> n >> s) {
    if (find_name(names, n)==-1) {
      names.push_back(n);
      scores.push_back(s);
    } else {
      // now the same name n is entered twice, terminate the program
      error("the same name cannot be entered twice");
    }
  }

  // write out all the (name,score) pairs, one per line
  for (int i=0; i<names.size(); ++i) {
    cout << "(" << names[i] << "," << scores[i] << ")\n";
  }

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
