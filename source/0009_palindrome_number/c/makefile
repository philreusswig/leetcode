# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: palindrome_number.exe									# default target

palindrome_number.exe: palindrome_number.o
	gcc -o palindrome_number.exe palindrome_number.o

palindrome_number.o: palindrome_number.c
	gcc -c palindrome_number.c

clean:											# optional target
	rm palindrome_number.o palindrome_number.exe