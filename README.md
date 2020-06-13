# Welcome to the Blind Tic Tac Toe Tournament!

Dear Participant! 

If you are reading this, it means that you (yes, you!) have been chosen
out of possibly millions of applicants to take part in the most prestigious
Cerebral Sports Event existing today! The **Blind Tic Tac Toe Tournament**!

## What is Blind Tic Tac Toe?

Blind tic tac toe (henceforth bttt) is much like the more widely known 
regular tic tac toe (ttt), in that two players alternatingly place their tokens
on a 3x3 game board, and whosoever manages to complete a string of three of
their own tokens, be it in a row, column, or diagonal, wins.

    X . O
    . X O
    O X X

    ^ here X has won on a diagonal

The difference between bttt and ttt is, that in bttt you can't see the board
(hence the "blind" part)!

I can hear you ask, "Well, how in the heavens am I going to play, then!?" –
good that you should ask!

## How to Play
Here's how one turn of bttt looks like:

1.  The game master – who is the only person who can see the board – tells you
    that it's **time for your turn**, and the number of the turn, e.g. "turn 3".
2.  You then have a good, hard think about it and tell the game master
    **which square** you would like to place your token on for this turn.
3.  Since you can't see the board, it's impossible for you to know if the square
    you attempted to place your token on has already been taken by your 
    opponent (in fact, you don't even know if you're the first or second
    player). If the square you attempted to move on during step 2 was already
    taken by your opponent, the game master will immediately ask you again to
    make your move **for the same turn**. This can happen any number of times
    in a row, should you keep choosing squares that are already occupied by 
    your opponent.
4.  You **immediately forfeit** the game should you
    1.  Choose a square that does not exist
    2.  Choose a square that you have chosen before

## Creating a Player

Your task is simple. Implement this function:

`int make_move_1(int turn)`

And you're done! That wasn't so bad, was it? Have a good day!

Well, maybe some more implementation details are warranted. Here goes:

As per **rule 1** (see above), the function *make_move_1* will be called at 
least once per turn. A turn is complete once player 1 and player 2 have 
successfully made their move, or else one of the players has forfeit or won 
the game.

The function *make_move_1* takes one argument, which is the *turn* that is 
currently being played. The turn number is monotonic, that means it
either increases from call to call or stays the same, which is a sign to tell
you that you chose a square occupied by your opponent (**rule 3**).

The function should return a number between 0 and 8 inclusively, corresponding
to the square you wish to place your token on (**rule 2**). 
The squares are numbered thusly:

    0 1 2
    3 4 5
    6 7 8

Should your function ever return any value outside the interval 0 to 8, 
you forfeit the game immediately (see **rule 4**).

**Please note:** It will never be the case that the function will be called
a second time if you chose a square occupied by *yourself*, because that would
mean that you played the same square twice... Which leads to immediate forfeit
(see **rule 4**).

## How to Run the Tournament

Place your function `make_move_1` into the file called *make_move_1* (easy!),
and you're good to go!

Just enter the project directory in your shell and type `make` to compile
and run the tournament.

**Enjoy!**
