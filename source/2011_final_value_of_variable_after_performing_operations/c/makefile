# rule: pre-requisite-1 pre-requisite-2 ...
#	 command

all: final_value_of_variable_after_performing_operations.exe									# default target

final_value_of_variable_after_performing_operations.exe: final_value_of_variable_after_performing_operations.o
	gcc -o final_value_of_variable_after_performing_operations.exe final_value_of_variable_after_performing_operations.o

final_value_of_variable_after_performing_operations.o: final_value_of_variable_after_performing_operations.c
	gcc -c final_value_of_variable_after_performing_operations.c

clean:											# optional target
	rm final_value_of_variable_after_performing_operations.o final_value_of_variable_after_performing_operations.exe