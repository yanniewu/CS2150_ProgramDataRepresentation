# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

a.out: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLNode.o AVLTree.o AVLPathTest.o -o a.out

AVLPathTest.o: AVLPathTest.cpp AVLNode.h AVLNode.cpp AVLTree.h AVLTree.cpp

AVLNode.o: AVLNode.h AVLNode.cpp

AVLTree.o: AVLTree.h AVLTree.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out
