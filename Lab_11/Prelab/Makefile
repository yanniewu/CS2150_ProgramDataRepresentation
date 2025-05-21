CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 
DEBUG=-g

a.out: topological.o
	$(CXX) $(DEBUG) topological.o -o a.out
	doxygen
		
topological.o: topological.cpp


.PHONY: clean
clean:
	-rm -f *.o a.out
