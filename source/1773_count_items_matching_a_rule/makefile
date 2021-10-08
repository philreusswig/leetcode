# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: count_items_matching_a_rule.exe									# default target

count_items_matching_a_rule.exe: count_items_matching_a_rule.o
	gcc -o count_items_matching_a_rule.exe count_items_matching_a_rule.o

count_items_matching_a_rule.o: count_items_matching_a_rule.c
	gcc -c count_items_matching_a_rule.c

clean:											# optional target
	rm count_items_matching_a_rule.o count_items_matching_a_rule.exe