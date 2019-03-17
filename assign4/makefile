#
# PROGRAM:    assign4
# PROGRAMMER: Damler, Lucas
# LOGON ID:   z1761739
# DATE DUE:   09 MAR 2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o Matrix.o
	g++ $(CCFLAGS) -o assign4 assign4.o Matrix.o

# Rules to compile source code file to object code
assign4.o: assign4.cpp Matrix.h
	g++ $(CCFLAGS) -c assign4.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4





