// name-and-value pairs
// look up names by the score as the key

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

  // look up
  cout << "\nNow you can enter a score, to look up all the names with that score, enter '|' to quit:\n";
  cin.clear();       // restore to good state, otherwise the program will exit
  cin >> n;          // to eat the "more" or others in the terminator "No more"
  while (cin >> s) {
    vector<int> indices;
    for (int i=0; i<scores.size(); ++i) {
      if (s==scores[i])
        indices.push_back(i);
    }
    if (indices.size()==0) {
      cout << "score not found\n";
    } else {
      cout << "Who are with the score " << s << "?\n";
      for (int i=0; i<indices.size(); ++i)
        cout << "    " << names[indices[i]] << '\n';
    }
    cout << "\nTry more, or enter '|' to quit:\n";
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
