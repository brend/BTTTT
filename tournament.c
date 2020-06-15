#include <stdlib.h> 
#include <stdio.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <string.h>

#include "make_move_1.h"
#include "make_move_2.h"

int play_game(
  int (*player1)(int),
  const char *name1,
  int (*player2)(int),
  const char *name2
);

const int default_game_count = 10;

const char *default_name1 = "you";
const char *default_name2 = "the computer";

int main(int argc, const char **argv) {  
  int game_count = default_game_count;
  
  if (argc > 1) {
    game_count = atoi(argv[1]);
    
    if (game_count < 1) {
      printf("I don't like the game count of %s; using %d instead.\n", argv[1], default_game_count);
      game_count = default_game_count;
    }
  }
  
  int score1 = 0;
  int score2 = 0;
  
  printf("Welcome to the Blind Tic Tac Toe tournament!\n%d games will be played.\nMay the best AI win.\n\n", game_count);
  
  for (int game = 1; game <= game_count; ++game) {
    printf("*** GAME %d BEGINS!\n", game);
    
    int even_game = game % 2;
    int (*player1)(int) = even_game ? make_move_1 : make_move_2;
    int (*player2)(int) = even_game ? make_move_2 : make_move_1;
    const char *name1 = even_game ? default_name1 : default_name2;
    const char *name2 = even_game ? default_name2 : default_name1;
    
    int result = play_game(player1, name1, player2, name2);
    
    if (result < 0 || result > 2) {
      printf("*** Error: game returned %d\n", result);
      continue;
    }
    
    if (result == 1) {
      if (even_game) {
        ++score1;
      } else {
        ++score2;
      }
    } else if (result == 2) {
      if (even_game) {
        ++score2;
      } else {
        ++score1;
      }
    }
  }
  
  printf("*** Tournament results: ***\n%d games were played.\nScore %s: %d\nScore %s: %d\nDraws: %d\n",
    game_count, default_name1, score1, default_name2, score2, game_count - (score1 + score2));
    
  if (score1 > score2) {
    printf("%s wins the tournament!\n", default_name1);
  } else if (score2 > score1) {
    printf("%s wins the tournament!\n", default_name2);
  } else {
    printf("The tournament is a draw!\n");
  }
  
  return 0;
}