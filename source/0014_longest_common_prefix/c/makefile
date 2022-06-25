# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: longest_common_prefix.exe									# default target

longest_common_prefix.exe: longest_common_prefix.o
	gcc -o longest_common_prefix.exe longest_common_prefix.o

longest_common_prefix.o: longest_common_prefix.c
	gcc -c longest_common_prefix.c

clean:											# optional target
	rm longest_common_prefix.o longest_common_prefix.exe