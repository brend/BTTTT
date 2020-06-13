GAME_COUNT=10

run: dirs bttt tournament
	bin/tournament $(GAME_COUNT)
	
bttt: game mm1 mm2
	gcc -Wall obj/game.o obj/make_move_1.o obj/make_move_2.o -o bin/game

mm1: make_move_1.c
	gcc -c -Wall make_move_1.c -o obj/make_move_1.o
	
mm2: make_move_2.c
	gcc -c -Wall make_move_2.c -o obj/make_move_2.o
	
tournament: tournament.c
	gcc -Wall tournament.c -o bin/tournament

game: game.c
	gcc -c -Wall game.c -o obj/game.o
	
dirs: obj bin
	
obj:
	mkdir obj
	
bin:
	mkdir bin
	
clean:
	rm obj/make_move_1.o obj/make_move_2.o obj/game.o bin/game bin/tournament
	