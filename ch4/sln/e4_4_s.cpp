// a numbers guessing game
//
// author: Ryan Duan <duanpanda@gmail.com>
// date: Jan. 3, 2012

/* Note: This program behaves like a binary search. */

#include "../../std_lib_facilities.h"

int g_small = 1;
int g_big = 100;

bool yes_or_no()
{
  char ans = ' ';
  cin >> ans;
  return ans == 'y';
}

char get_answer()
{
  char ans = ' ';
  while (ans != 's' && ans != 'b') {
    cin >> ans;
  }
  return ans;
}

void smaller()
{
  g_big = (g_small+g_big)/2 - 1;
}

void bigger()
{
  g_small = (g_small+g_big)/2 + 1;
}

int guess()
{
  int middle = (g_small+g_big)/2;
  cout << middle << ": Is it? (y or n) ";
  if (!yes_or_no()) {
    cout << "Is it smaller or bigger than your number? (s or b) ";
    char answer = get_answer();
    if (answer == 's') {
      bigger();
      return guess();
    }
    else {
      smaller();
      return guess();
    }
  }
  else
    return middle;
}

int main()
{
  int n = 0;
  cout << "Please think of an integer between " << g_small << " and " << g_big << ", input here: ";
  while(cin >> n && (n < g_small || n > g_big)) {
    cout << "Out of range.  Try again: ";
  }
  if (!cin) error("Some error occurs in input.");

  int g = guess();
  if (g == n)
    cout << "Succsessful! The number is " << g << ".\n";
  else
    cout << "Sorry, this program fails to guess your number. You cheated me.\n";

  return 0;
}
