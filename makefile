run: bttt
	./bttt
	
bttt: tournament mm1 mm2
	gcc -Wall tournament.o make_move_1.o make_move_2.o -o bttt

mm1: make_move_1.o
	gcc -c -Wall make_move_1.c
	
mm2: make_move_2.o
	gcc -c -Wall make_move_2.c
	
tournament:
	gcc -c -Wall tournament.c
