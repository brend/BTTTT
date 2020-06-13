#include <stdlib.h> 
#include <stdio.h>

int main() {
  const int game_count = 10;
  int score1 = 0;
  int score2 = 0;
  
  printf("Welcome to the Blind Tic Tac Toe tournament!\n%d games will be played.\nMay the best AI win.\n\n", game_count);
  
  for (int game = 0; game < game_count; ++game) {
    int result = system("bin/game");
    
    if (result < 0 || result > 2) {
      printf("*** Error: game returned %d\n", result);
      continue;
    }
    
    if (result == 1) {
      ++score1;
    } else if (result == 2) {
      ++score2;
    }
  }
  
  printf("*** Tournament results: ***\n%d games were played.\nScore player 1: %d\nScore player 2: %d\nDraws: %d\n",
    game_count, score1, score2, game_count - (score1 + score2));
    
  if (score1 > score2) {
    printf("Player 1 wins the tournament!\n");
  } else if (score2 > score1) {
    printf("Player 2 wins the tournament!\n");
  } else {
    printf("The tournament is a draw!\n");
  }
  
  return 0;
}