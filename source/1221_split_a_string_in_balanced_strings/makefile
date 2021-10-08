# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: split_a_string_in_balanced_strings.exe									# default target

split_a_string_in_balanced_strings.exe: split_a_string_in_balanced_strings.o
	gcc -o split_a_string_in_balanced_strings.exe split_a_string_in_balanced_strings.o

split_a_string_in_balanced_strings.o: split_a_string_in_balanced_strings.c
	gcc -c split_a_string_in_balanced_strings.c

clean:											# optional target
	rm split_a_string_in_balanced_strings.o split_a_string_in_balanced_strings.exe