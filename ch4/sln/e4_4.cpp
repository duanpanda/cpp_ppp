// a numbers guessing game
//
// author: Ryan Duan <duanpanda@gmail.com>
// date: Dec. 20, 2011

/* Note: This program behaves like a binary search. */

#include "../../std_lib_facilities.h"

// Ask the user if the number is in range [low, high].
// If user input 'y', return true; otherwise return false.
//
// Pre: low <= high
bool is_in_range(int low, int high)
{
  char ans = 'n';
  if (low == high)
    cout << "Is it " << low << "? (y or n) ";
  else
    cout << "Is this number in range [" << low << ", " << high << "]? (y or n) ";
  cin >> ans;
  return ans == 'y';
}

// behave like a binary search
int guess(int low, int high)
{
  // So it must be in range [low, high].
  if (low == high)
    return low;
  else {
    int middle = (low + high) / 2;
    if (is_in_range(low, middle))
      return guess(low, middle);
    else
      return guess(middle + 1, high);
  }
}

int main()
{
  int n = 0;
  const int low = 1;
  const int high = 100;
  cout << "Please think of an integer between " << low << " and " << high << ", input here: ";
  while(cin >> n && (n < low || n > high)) {
    cout << "Out of range.  Try again: ";
  }
  if (!cin) error("Some error occurs in input.");

  int g = guess(low, high);
  if (g == n)
    cout << "Succsessful! The number is " << g << ".\n";
  else
    cout << "Sorry, this program fails to guess your number. You cheated me.\n";

  return 0;
}
