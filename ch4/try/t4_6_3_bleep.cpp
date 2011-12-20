// Bleep out the words that are in the dictionary which is called "disliked
// words".

#include "../../std_lib_facilities.h"

int main()
{
  // disliked words
  vector<string> disliked(3);
  disliked[0] = "Broccoli";
  disliked[1] = "Ape";
  disliked[2] = "Chimpanzee";
 
  vector<string> words;
  string temp;
  while (cin >> temp)           // read whitespace-separated words
    words.push_back(temp);      // put into vector

  cout << "Number of words: " << words.size() << endl;

  for (int i = 0; i < words.size(); ++i) {
    int j;
    for (j = 0; j < disliked.size(); ++j) {
      if (words[i] == disliked[j]) {
        cout << "BLEEP\n";
        break;
      }
    }
    if (j == disliked.size())
      cout << words[i] << "\n";
  }

  return 0;
}
