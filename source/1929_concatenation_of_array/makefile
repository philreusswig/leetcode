# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: concatenation_of_array.exe									# default target

concatenation_of_array.exe: concatenation_of_array.o
	gcc -o concatenation_of_array.exe concatenation_of_array.o

concatenation_of_array.o: concatenation_of_array.c
	gcc -c concatenation_of_array.c

clean:											# optional target
	rm concatenation_of_array.o
	rm concatenation_of_array.exe