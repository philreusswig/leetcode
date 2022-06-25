# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: valid_parentheses.exe									# default target

valid_parentheses.exe: valid_parentheses.o
	gcc -o valid_parentheses.exe valid_parentheses.o

valid_parentheses.o: valid_parentheses.c
	gcc -c valid_parentheses.c

clean:											# optional target
	rm valid_parentheses.o valid_parentheses.exe