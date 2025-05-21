//Yannie Wu
//ylw4sj
//wordPuzzle.cpp

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string> 
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class hashTable{
public:
	hashTable(int size);
	~hashTable();
	void insert(string word);
	unsigned int hash(string word);
	bool check(string word);

	

private:
	vector<list<string> > table;
	int tableSize;

};

#endif