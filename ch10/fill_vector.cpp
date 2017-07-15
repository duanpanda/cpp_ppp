/// IO error handling
/// fill the vector with a sequence of integers that be terminated by the
/// asterisk character * or an "end of file".  For example:
///     1 2 3 4 5 *

#include "../std_lib_facilities.h"

// read integers from ist into v until we reach eof() or terminator
// void fill_vector(istream& ist, vector<int>& v, char terminator)
// {
//     for (int i; ist >> i; ) v.push_back(i);
//     if (ist.eof()) return; // fine: we found the end of file
//     if (ist.bad()) error("ist is bad"); // stream corrupted; let’s get out of here!
//     if (ist.fail()) { // clean up the mess as best we can and report the problem
//         ist.clear();  // clear stream state, so that we can look for terminator
//         char c;
//         ist >> c; // read a character, hopefully terminator
//         if (c != terminator) { // unexpected character
//             ist.unget(); // put that character back
//             ist.clear(ios_base::failbit); // set the state to fail()
//         }
//     }
// }

// read integers from ist into v until we reach eof() or terminator
void fill_vector(istream& ist, vector<int>& v, char terminator)
{
    for (int i; ist >> i; ) v.push_back(i);
    if (ist.eof()) return;      // fine: we found the end of file

    // not good() and not bad() and not eof(), ist must be fail()
    cerr << "Enter the failure state." << endl;
    ist.clear();                // clear stream state
    char c;
    ist >> c;                     // read a character, hopefully terminator
    cout << c << endl;
    if (c != terminator) {        // ouch: not the terminator, so we must fail
        cout << "ouch: not the terminator, so we must fail" << endl;
        ist.unget();              // maybe my caller can use that character
        ist.clear(ios_base::failbit); // set the state to fail()
    }
}

int main()
{
    vector<int> v;
    ifstream ist("input.txt");
    // make ist throw if it goes bad
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    fill_vector(ist, v, '*');
    for (int i : v) {
        cout << i << ' ';
    }
    keep_window_open();
    return 0;
}
