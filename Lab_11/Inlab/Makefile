CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -std=c++11 -Wall -O2 
DEBUG=-g

a.out: traveling.o middleearth.o
	$(CXX) $(DEBUG) traveling.o middleearth.o -o a.out
	doxygen
		
traveling.o: traveling.cpp

middleearth.o: middleearth.cpp middleearth.h


.PHONY: clean
clean:
	-rm -f *.o a.out
