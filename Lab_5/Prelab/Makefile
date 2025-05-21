CXX=clang++ 
CXXFLAGS=-Wall -O2 
DEBUG=-g

a.out: TreeCalcTest.o TreeCalc.o TreeNode.o 
			$(CXX) $(DEBUG) TreeCalcTest.o TreeCalc.o TreeNode.o -o a.out
		
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.cpp TreeCalc.h TreeNode.cpp TreeNode.h

TreeCalc.o: TreeCalc.cpp TreeCalc.h 

TreeNode.o: TreeNode.cpp TreeNode.h .

.PHONY: clean
clean:
	-rm -f *.o a.out
