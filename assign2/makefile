#
# PROGRAM:    assign2
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: Assign2.o CreditAccount.o AccountDB.o
	g++ $(CCFLAGS) -o assign2 Assign2.o CreditAccount.o AccountDB.o

# Rules to compile source code files to object code
Assign2.o: Assign2.cpp AccountDB.h
	g++ $(CCFLAGS) -c Assign2.cpp

CreditAccount.o: CreditAccount.cpp CreditAccount.h
	g++ $(CCFLAGS) -c CreditAccount.cpp

AccountDB.o: AccountDB.cpp AccountDB.h
	g++ $(CCFLAGS) -c AccountDB.cpp

# The AccountDB class depends on the CreditAccount class
AccountDB.h: CreditAccount.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
