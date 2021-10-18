# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: template_src.exe									# default target

template_src.exe: template_src.o
	gcc -o template_src.exe template_src.o

template_src.o: template_src.c
	gcc -c template_src.c

clean:											# optional target
	rm template_src.o template_src.exe