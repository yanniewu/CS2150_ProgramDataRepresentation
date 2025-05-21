CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 
DEBUG=-g

a.out: hashTable.o wordPuzzle.o timer.o
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o -o a.out
		
wordPuzzle.o: wordPuzzle.cpp hashTable.cpp hashTable.h timer.cpp timer.h

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o a.out
