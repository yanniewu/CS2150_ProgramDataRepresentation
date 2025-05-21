# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

a.out: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) BinaryNode.o BinarySearchTree.o BSTPathTest.o -o a.out

BSTPathTest.o: BSTPathTest.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp

BinaryNode.o: BinaryNode.h BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out
