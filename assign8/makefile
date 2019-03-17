#
# PROGRAM:    assign8
# PROGRAMMER: Damler, Lucas
# LOGON ID:   z1761739
# DATE DUE:   25 APR 2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code file to object code
assign8.o: assign8.cpp sorts.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
