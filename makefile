GAME_COUNT=10

run: dirs bttt
	bin/bttt $(GAME_COUNT)
	
bttt: tournament game mm1 mm2 
	gcc -Wall obj/tournament.o obj/game.o obj/make_move_1.o obj/make_move_2.o -o bin/bttt
	
mm1: make_move_1.c
	gcc -c -Wall make_move_1.c -o obj/make_move_1.o
	
mm2: make_move_2.c
	gcc -c -Wall make_move_2.c -o obj/make_move_2.o
	
tournament: tournament.c
	gcc -c -Wall tournament.c -o obj/tournament.o

game: game.c
	gcc -c -Wall game.c -o obj/game.o
	
dirs: obj bin
	
obj:
	mkdir obj
	
bin:
	mkdir bin
	
clean:
	rm obj/make_move_1.o obj/make_move_2.o obj/game.o bin/game bin/tournament
	