CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 
DEBUG=-g

a.out: huffmandec.o heap.o heapNode.o
	$(CXX) $(DEBUG) huffmandec.o heap.o heapNode.o -o a.out
		
huffmandec.o: huffmandec.cpp heap.cpp heap.h heapNode.cpp heapNode.h

heap.o: heap.cpp heap.h

heapNode.o: heapNode.cpp heapNode.h



.PHONY: clean
clean:
	-rm -f *.o a.out
