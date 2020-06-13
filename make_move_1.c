#include <stdlib.h>

/*
  Welcome to the Blind Tic Tac Toe Tournament!

  Please read the explanation and rules in README.md!

  Then get to work on implementing this function.
*/

/*
  make_move_1

  parameters:
    turn: the current turn number

  returns:
    a number between 0 and 8 inclusively,
    signifying the square you'd like to place your token on.
*/
int make_move_1(int turn) {
  return rand() % 9;
}