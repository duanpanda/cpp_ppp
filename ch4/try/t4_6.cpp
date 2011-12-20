// vector
#include "../../std_lib_facilities.h"

int main()
{
  vector<double> vd(1000, -1.2);
  vd[20000] = 4.7;              // runtime error: Range_error
  return 0;
}
