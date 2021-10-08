# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: two_sum.exe									# default target

two_sum.exe: two_sum.o
	gcc -o two_sum.exe two_sum.o

two_sum.o: two_sum.c
	gcc -c two_sum.c

clean:											# optional target
	rm two_sum.o two_sum.exe