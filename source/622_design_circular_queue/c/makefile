# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: design_circular_queue_src.exe									# default target

design_circular_queue_src.exe: design_circular_queue_src.o
	gcc -o design_circular_queue_src.exe design_circular_queue_src.o

design_circular_queue_src.o: design_circular_queue_src.c
	gcc -c design_circular_queue_src.c

clean:											# optional target
	rm design_circular_queue_src.o design_circular_queue_src.exe