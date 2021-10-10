# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: build_array_from_permutation.exe									# default target

build_array_from_permutation.exe: build_array_from_permutation.o
	gcc -o build_array_from_permutation.exe build_array_from_permutation.o

build_array_from_permutation.o: build_array_from_permutation.c
	gcc -c build_array_from_permutation.c

clean:											# optional target
	rm build_array_from_permutation.o build_array_from_permutation.exe