//heap.s
//Yannie Wu
//ylw4sj

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "heapNode.h"

using namespace std;


class binary_heap {
public:
    binary_heap();
    binary_heap(vector<heapNode*> vec);
    ~binary_heap();

    void insert(heapNode* node);
    //void insert(heapNode*& node); //???
    heapNode* const deleteMin();
    heapNode* const findMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    
    vector<heapNode*> heap;

private:
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif