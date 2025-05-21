CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -std=c++11 -Wall -O2 
DEBUG=-g

a.out: puzzlesolver.o
	$(CXX) $(DEBUG) puzzlesolver.o -o a.out
	doxygen
		
puzzlesolver.o: puzzlesolver.cpp



.PHONY: clean
clean:
	-rm -f *.o a.out
