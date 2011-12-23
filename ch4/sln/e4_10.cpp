// Game "Rock, Paper, Scissors"

#include "../../std_lib_facilities.h"

int main()
try
{
  int user_score = 0;
  int comp_score = 0;
  int draws = 0;

  cout << "Game Rock, Paper, Scissors Start!\n";

  srand((unsigned)time(0));

  while (true) {
    cout << "\nEnter \"rock\", \"paper\" or \"scissor\", or you can enter 'r', 'p' or 's' respectively. Enter \"q\" to exit.\n";
    string s;
    cin >> s;

    int user_play = 1;
    string user_s = "?";
    if (s == "rock" || s == "r") {
      user_play = 1;
      user_s = "rock";
    }
    else if (s == "paper" || s == "p") {
      user_play = 2;
      user_s = "paper";
    }
    else if (s == "scissor" || s == "s") {
      user_play = 3;
      user_s = "scissor";
    }
    else if (s == "q")
      return 0;                 // exit
    else {
      cout << "Input error. Try again.\n";
      continue;
    }

    int comp_play = rand() % 3 + 1;

    string next_s = "?";
    switch (comp_play) {
    case 1:
      next_s = "rock";
      break;
    case 2:
      next_s = "paper";
      break;
    case 3:
      next_s = "scissor";
      break;
    default:
      error("God, computer error!");
      break;
    }

    cout << "Yours: " << user_s << ", Mine: " << next_s << '\n';
    string who_win = "I win.";
    if (user_play == comp_play) {
      ++draws;
      who_win = "A draw.";
    }
    else {
      if (user_play == 1 && comp_play == 3 ||
          user_play == 2 && comp_play == 1 ||
          user_play == 3 && comp_play == 2) {
        who_win = "You win!";
        ++user_score;
      }
      else {
        ++comp_score;
      }
    }

    cout << who_win << '\n';

    cout << "You wins: " << user_score << ", I wins: " << comp_score
         << ", Draws: " << draws << '\n';
    cout << "\nTry again.\n";
  }
  return 0;
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "exiting\n";
  return 2;
}
/*
  Note:
   1 represents rock,
   2 represents paper,
   3 represents scissor.

   Hard to remember.  Hard to modify!
   Use enumeration instead!
*/
