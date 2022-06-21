# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: roman_to_integer.exe									# default target

roman_to_integer.exe: roman_to_integer.o
	gcc -o roman_to_integer.exe roman_to_integer.o

roman_to_integer.o: roman_to_integer.c
	gcc -c roman_to_integer.c

clean:											# optional target
	rm roman_to_integer.o roman_to_integer.exe