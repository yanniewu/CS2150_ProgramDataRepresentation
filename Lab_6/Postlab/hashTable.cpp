//Yannie Wu
//ylw4sj
//wordPuzzle.cpp

#include "hashTable.h"
#include <iostream>
#include <string> 
#include <tgmath.h>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

hashTable::hashTable(int size){
	tableSize = size;
	for(int i=0; i<tableSize; i++){
		list<string> list;
		table.push_back(list);
	}
}

hashTable::~hashTable(){

}

void hashTable::insert(string word){
	unsigned int index = hash(word);
	table[index].push_back(word);
}

unsigned int hashTable::hash(string word){
	unsigned int index = 0;
	int pow = 1;
	for(int i=0; i<word.length(); i++){
		index += (word[i] - 'a' + 1)*pow;   //index += int(word[i])*pow
		pow = pow*37;
	}

	return index % tableSize;
}

bool hashTable::check(string word){
	unsigned int index = hash(word);
	return find(table[index].begin(), table[index].end(), word) != table[index].end();
}

