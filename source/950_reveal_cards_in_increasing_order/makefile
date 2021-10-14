# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: reveal_cards_in_increasing_order.exe									# default target

reveal_cards_in_increasing_order.exe: reveal_cards_in_increasing_order.o
	gcc -o reveal_cards_in_increasing_order.exe reveal_cards_in_increasing_order.o

reveal_cards_in_increasing_order.o: reveal_cards_in_increasing_order.c
	gcc -c reveal_cards_in_increasing_order.c

clean:											# optional target
	rm reveal_cards_in_increasing_order.o reveal_cards_in_increasing_order.exe