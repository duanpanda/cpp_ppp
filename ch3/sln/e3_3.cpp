int main()
{
  int string = 0;            // ok
  int double = 0;            // error: expected unqualified-id before '=' token
  int 0a = 8;                // error: invalid suffix "a" on integer constant
  int $a$b = 5;              // ok on g++ 4.4
}
