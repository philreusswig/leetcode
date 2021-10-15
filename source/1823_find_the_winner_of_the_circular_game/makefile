# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: find_the_winner_of_the_circular_game.exe									# default target

find_the_winner_of_the_circular_game.exe: find_the_winner_of_the_circular_game.o
	gcc -o find_the_winner_of_the_circular_game.exe find_the_winner_of_the_circular_game.o

find_the_winner_of_the_circular_game.o: find_the_winner_of_the_circular_game.c
	gcc -c find_the_winner_of_the_circular_game.c

clean:											# optional target
	rm find_the_winner_of_the_circular_game.o find_the_winner_of_the_circular_game.exe