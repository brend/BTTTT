run: bttt tournament
	./tournament
	
bttt: game mm1 mm2
	gcc -Wall game.o make_move_1.o make_move_2.o -o game

mm1: make_move_1.c
	gcc -c -Wall make_move_1.c
	
mm2: make_move_2.c
	gcc -c -Wall make_move_2.c
	
tournament: tournament.c
	gcc -Wall tournament.c -o tournament

game: game.c
	gcc -c -Wall game.c
	
clean:
	rm make_move_1.o make_move_2.o game.o game tournament
	