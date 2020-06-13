#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "make_move_1.h"
#include "make_move_2.h"

const int empty = 0;
const int symbol1 = 1;
const int symbol2 = 2;

int invalid(int move) {
  return move < 0 || move >= 9;
}

int other(int player) {
  return (player == symbol1) ? symbol2 : symbol1;
}

int attempt(int* board, int player, int* attempts, int turn) {
  int move = (player == symbol1) ? make_move_1(turn) : make_move_2(turn);
  
  if (invalid(move)) {
    printf("player %d made an invalid move (%d)\n", player, move);
    return -1;
  }
  
  if (attempts[move] != 0) {
    printf("player %d chose a square they chose once before (%d)\n", player, move);
    return -2;
  }
  
  attempts[move] += 1;

  if (board[move] != empty) {
    printf("player %d attempts %d, discovers existing token of player %d\n", player, move, other(player));
    return attempt(board, player, attempts, turn);
  }
  
  board[move] = player;
  
  return move;
}

int over(int *board) {
  return (board[0] != empty && board[0] == board[1] && board[1] == board[2])
    || (board[3] != empty && board[3] == board[4] && board[4] == board[5])
    || (board[6] != empty && board[6] == board[7] && board[7] == board[8])
 
    || (board[0] != empty && board[0] == board[3] && board[3] == board[6])
    || (board[1] != empty && board[1] == board[4] && board[4] == board[7])
    || (board[2] != empty && board[2] == board[5] && board[5] == board[8])
       
    || (board[0] != empty && board[0] == board[4] && board[4] == board[8])
    || (board[2] != empty && board[2] == board[4] && board[4] == board[6]);
}

int full(int *board) {
  for (int i = 0; i < 9; ++i) {
    if (board[i] == empty) {
      return 0;
    }
  }
  
  return 1;
}

const char* token[] = {".", "X", "O"};

void print_board(int *board) {
  printf("%s %s %s\n%s %s %s\n%s %s %s\n\n", 
    token[board[0]], token[board[1]], token[board[2]], 
    token[board[3]], token[board[4]], token[board[5]], 
    token[board[6]], token[board[7]], token[board[8]]);
}

void run() {
  
  srand(time(NULL));
  
  int turn = 0;
  int board[] = {0,0,0, 0,0,0, 0,0,0};
  int attempts1[] = {0,0,0, 0,0,0, 0,0,0};
  int attempts2[] = {0,0,0, 0,0,0, 0,0,0};
  
  while (turn < 9) {
    printf("*** turn %d\n", turn);
    
    int result1 = attempt(board, symbol1, attempts1, turn);
    
    if (result1 < 0) {
      printf("player 2 wins\n");
      return;
    }
    
    printf("player 1 choses %d\n", result1);
    
    print_board(board);
    
    if (over(board)) {
      printf("player 1 wins!\n");
      return;
    }
    
    int result2 = attempt(board, symbol2, attempts2, turn);
    
    if (result2 < 0) {
      printf("player 1 wins\n");
      return;
    }
    
    printf("player 2 choses %d\n", result2);
    
    print_board(board);
    
    if (over(board)) {
      printf("player 2 wins!\n");
      return;
    }
    
    if (full(board)) {
      printf("it's a tie!\n");
      return;
    }
    
    ++turn;
  }
}

int main() {
  run();
}