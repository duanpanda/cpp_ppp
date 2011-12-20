// for loop

#include "../../std_lib_facilities.h"

int main()
{
  char i;

  for (i = 'a'; i <= 'z'; ++i)
    cout << i << '\t' << int(i) << '\n';

  for (i = 'A'; i <= 'Z'; ++i)
    cout << i << '\t' << int(i) << '\n';

  for (i = '0'; i <= '9'; ++i)
    cout << i << '\t' << int(i) << '\n';

  return 0;
}
