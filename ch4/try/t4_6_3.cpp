// simple dictionary: list of sorted words

#include "../../std_lib_facilities.h"

int main()
{
  vector<string> words;
  string temp;
  while (cin >> temp)           // read whitespace-separated words
    words.push_back(temp);      // put into vector

  cout << "Number of words: " << words.size() << endl;

  sort(words.begin(), words.end()); // sort "from beginning to end"

  for (int i = 0; i < words.size(); ++i)
    if (i == 0 || words[i-1] != words[i]) // is this a new word?
      cout << words[i] << "\n";

  return 0;
}
