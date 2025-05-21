//heapNode.cpp
//Yannie Wu
//ylw4sj

#ifndef HEAPNODE_H
#define HEAPNODE_H
#include <string>

using namespace std;

class heapNode {
public:
	heapNode();
    heapNode(char character, int frequency); // Constructor
    int freq;
    char c;
    heapNode* left;
    heapNode* right;
};

#endif






