#include "../../std_lib_facilities.h"

int main()
{
  int pennies = 0;              // 1-cent coins
  int nickels = 0;              // 5-cent coins
  int dimes = 0;                // 10-cent coins
  int quarters = 0;             // 25-cent coins
  int half_dollars = 0;         // 50-cent coins
  int one_dollars = 0;          // 100-cent coins
  double value = 0;

  cout << "How many number of penny coins do you have?\n";
  cin >> pennies;
  cout << "You have " << pennies;
  if (pennies == 1)
    cout << " penny.\n";
  else
    cout << " pennies.\n";

  cout << "How many number of nickel coins do you have?\n";
  cin >> nickels;
  cout << "You have " << nickels;
  if (nickels == 1)
    cout << " nickel.\n";
  else
    cout << " nickels.\n";

  cout << "How many number of dime coins do you have?\n";
  cin >> dimes;
  cout << "You have " << dimes;
  if (dimes == 1)
    cout << " dime.\n";
  else
    cout << " dimes.\n";

  cout << "How many number of quarter coins do you have?\n";
  cin >> quarters;
  cout << "You have " << quarters;
  if (quarters == 1)
    cout << " quarter.\n";
  else
    cout << " quarters.\n";

  cout << "How many number of half dollar coins do you have?\n";
  cin >> half_dollars;
  cout << "You have " << half_dollars;
  if (half_dollars == 1)
    cout << " half dollar.\n";
  else
    cout << " half dollars.\n";

  cout << "How many number of one dollar coins do you have?\n";
  cin >> one_dollars;
  cout << "You have " << one_dollars;
  if (one_dollars == 1)
    cout << " one-dollar coin.\n";
  else
    cout << " one-dollar coins.\n";

  value = (pennies + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + one_dollars * 100) / 100.0;
  cout << "The value of all your coins is " << value << " dollars.\n";

  return 0;
}
