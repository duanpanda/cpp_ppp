#include <iostream>
using namespace std;

int main()
{
  string s1 = "Hello, World!";
  string s2 = "1.2";
  int a = 120;
  char *pc = reinterpret_cast<char*>(&a); // static_cast causes compile error
  string *pstr = reinterpret_cast<string*>(&a);

  cout << "sizeof(int) == " << sizeof(int) << '\n'
       << "sizeof(char) == " << sizeof(char) << '\n'
       << "sizeof(long) == " << sizeof(long) << '\n'
       << "sizeof(short) == " << sizeof(short) << '\n'
       << "sizeof(long long) == " << sizeof(long long) << '\n'
       << "sizeof(double) == " << sizeof(double) << '\n'
       << "sizeof(string) == " << sizeof(string) << '\n'
       << "sizeof(s1) == " << sizeof(s1) << " (s1 is \"" << s1 << "\")" << '\n'
       << "sizeof(s2) == " << sizeof(s2) << " (s2 is \"" << s2 << "\")" << endl;

  cout << "a == " << a << '\n'
       << "*pc == " << *pc << endl;

  //  cout << "*pstr == " << *pstr << endl;
  cout << "*pstr causes segmentation fault on Linux." << endl;


  return 0;
}
