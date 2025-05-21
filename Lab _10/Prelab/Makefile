CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 
DEBUG=-g

a.out: huffmanenc.o heap.o heapNode.o
	$(CXX) $(DEBUG) huffmanenc.o heap.o heapNode.o -o a.out
		
huffmanenc.o: huffmanenc.cpp heap.cpp heap.h heapNode.cpp heapNode.h

heap.o: heap.cpp heap.h

heapNode.o: heapNode.cpp heapNode.h



.PHONY: clean
clean:
	-rm -f *.o a.out
