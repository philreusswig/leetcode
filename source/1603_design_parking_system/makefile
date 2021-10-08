# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: design_parking_system.exe									# default target

design_parking_system.exe: design_parking_system.o
	gcc -o design_parking_system.exe design_parking_system.o

design_parking_system.o: design_parking_system.c
	gcc -c design_parking_system.c

clean:											# optional target
	rm design_parking_system.o design_parking_system.exe