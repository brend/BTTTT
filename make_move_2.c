#include <stdlib.h>

int make_move_2(int turn) {
  static int board[] = {0,0,0, 0,0,0, 0,0,0};
  static int last_turn = -1;
  static int last_move = -1;
  
  if (turn == last_turn) {
    board[last_move] = 2;
  }
  
  int move;

  do {
    move = rand() % 9;
  } while (board[move] != 0);
  
  last_turn = turn;
  last_move = move;
  
  board[move] = 1;
  
  return move;
}
