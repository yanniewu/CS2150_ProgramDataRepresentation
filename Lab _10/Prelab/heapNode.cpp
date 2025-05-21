//heapNode.cpp
//Yannie Wu
//ylw4sj

#include "heapNode.h"
#include <string>
using namespace std;


// Default Constructor - left and right are NULL, value '?'
heapNode::heapNode(){
    cha = '?';
    freq = 0;
    left = NULL;
    right = NULL;
}
heapNode::heapNode(char character, int frequency) {
    cha = character;
    freq = frequency;
    left = NULL;
    right = NULL;
}