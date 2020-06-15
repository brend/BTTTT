#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int empty = 0;
const int symbol1 = 1;
const int symbol2 = 2;

int invalid(int move) {
  return move < 0 || move >= 9;
}

int attempt(
  int* board, 
  int player, 
  int (*make_move)(int),
  const char *name,
  int* attempts, 
  int turn,
  const char *other_name) 
{
  int move = make_move(turn);
  
  if (invalid(move)) {
    printf("%s made an invalid move (%d)\n", name, move);
    return -1;
  }
  
  if (attempts[move] != 0) {
    printf("%s chose a square they chose once before (%d)\n", name, move);
    return -2;
  }
  
  attempts[move] += 1;

  if (board[move] != empty) {
    printf("%s attempts %d, discovers existing token of %s\n", name, move, other_name);
    return attempt(board, player, make_move, name, attempts, turn, other_name);
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

int play_game(
  int (*player1)(int),
  const char *name1,
  int (*player2)(int),
  const char *name2
) {  
  int turn = 0;
  int board[] = {0,0,0, 0,0,0, 0,0,0};
  int attempts1[] = {0,0,0, 0,0,0, 0,0,0};
  int attempts2[] = {0,0,0, 0,0,0, 0,0,0};
  
  printf("*** X: %s\n*** O: %s\n", name1, name2);
  
  while (turn < 9) {
    printf("*** turn %d\n", turn);
    
    int result1 = attempt(board, symbol1, player1, name1, attempts1, turn, name2);
    
    if (result1 < 0) {
      printf("%s wins\n", name2);
      return 2;
    }
    
    printf("%s choses %d\n", name1, result1);
    
    print_board(board);
    
    if (over(board)) {
      printf("%s wins!\n", name1);
      return 1;
    }
    
    int result2 = attempt(board, symbol2, player2, name2, attempts2, turn, name1);
    
    if (result2 < 0) {
      printf("%s wins\n", name1);
      return 1;
    }
    
    printf("%s choses %d\n", name2, result2);
    
    print_board(board);
    
    if (over(board)) {
      printf("%s wins!\n", name2);
      return 2;
    }
    
    if (full(board)) {
      printf("it's a tie!\n");
      return 0;
    }
    
    ++turn;
  }
  
  return 0;
}
