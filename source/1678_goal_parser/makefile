# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: goal_parser.exe									# default target

goal_parser.exe: goal_parser.o
	gcc -o goal_parser.exe goal_parser.o

goal_parser.o: goal_parser.c
	gcc -c goal_parser.c

clean:											# optional target
	rm goal_parser.o goal_parser.exe