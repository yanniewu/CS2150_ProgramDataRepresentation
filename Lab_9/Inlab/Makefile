# Makefile for CS 2150 pre-lab 8
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX = clang

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g


# All of the .o files for our program
OBJECTS = linkedlist.o

# Compile our files into a.out
a.out: linkedlist.o
	$(CXX) $(CXXFLAGS) $(OBJECTS)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
