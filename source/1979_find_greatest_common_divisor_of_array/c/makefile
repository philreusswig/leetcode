# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: find_greatest_common_divisor_of_array.exe									# default target

find_greatest_common_divisor_of_array.exe: find_greatest_common_divisor_of_array.o
	gcc -o find_greatest_common_divisor_of_array.exe find_greatest_common_divisor_of_array.o

find_greatest_common_divisor_of_array.o: find_greatest_common_divisor_of_array.c
	gcc -c find_greatest_common_divisor_of_array.c

clean:											# optional target
	rm find_greatest_common_divisor_of_array.o find_greatest_common_divisor_of_array.exe