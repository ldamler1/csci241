#
# PROGRAM:    assign7
# PROGRAMMER: Damler, Lucas
# LOGON ID:   z1761739
# DATE DUE:   18 APR 2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rules to compile source code file to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
