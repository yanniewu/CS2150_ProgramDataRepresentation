//huffmanenc.cpp
//Yannie Wu
//ylw4sj
//Sources: fileio.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "heap.h"
#include <unordered_map>
using namespace std;

//Returns index of a key in a vector pair
int indexOf(vector<pair<char, int> > vect, char key){
	for(int i=0; i<vect.size(); i++){
		if(vect[i].first == key){
			return i;
		}
	}
	return -1;
}

//Sorts vector pair in ascending order by frequency
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

//Prefix traversal of Huffman tree 
void encode(heapNode* node, unordered_map<char, string> &map, string str){
	if(node == NULL){
		return;
	}
	if(node->left == NULL && node->right == NULL){
		map[node->cha] = str;
		if(node->cha == ' '){
			cout << "space " << map[node->cha] << endl;
		}
		else
		cout << node->cha << " " << map[node->cha] << endl;

	}
	encode(node->left, map, str + "0");
	encode(node->right, map, str + "1");
}


//Main method
int main(int argc, char** argv) {
	
	// verify the correct number of parameters
	if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    int length = 0;
    vector<pair <char, int> > vect;

    //Read file
    while (file.get(g)) {  
        //If g is an encodable character
        if(g >= 0x20 && g<= 0x7e){
        	//If "cha" does not already contain g
        	if(indexOf(vect, g) < 0){
        		vect.push_back(make_pair(g, 0));
        	}
        	//If "cha" already contains g, adds 1 to "freq"
        	vect[indexOf(vect, g)].second += 1;

        	//Counter for total number of symbols
        	length++;
        }
    }

    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    //Sort vector by frequency (ascending order)
     sort(vect.begin(), vect.end(), sortbysec);

     //Create nodes and insert into heap
     binary_heap heap;
     for(int i=0; i<vect.size(); i++){
     	heapNode* node = new heapNode(vect[i].first, vect[i].second);
     	heap.insert(node);

     }

     //Create Huffman tree
     while(heap.size() > 1){
     	heapNode* parent = new heapNode();
     	parent->left = heap.deleteMin();
     	parent->right = heap.deleteMin();

     	parent->freq = parent->left->freq + parent->right->freq;

     	heap.insert(parent);
     }

     //Traverse tree and get code for each character
     heapNode* root = heap.deleteMin();
     unordered_map<char, string> encoded;

     //Print characters and corresponding code
     encode(root, encoded, "");


     cout << "----------------------------------------" << endl;

     //Print out encoded text
     int bits = 0;
     while (file.get(g)) {
        cout << encoded[g] << " " ;
        bits += encoded[g].length();
     }
     cout << endl;

     int original = length*8;
     double ratio = (double)original/bits;

     //Calculate cost
     float cost = 0;

     for(int i=0; i<vect.size(); i++){   
     	double frequency = double(vect[i].second)/length;
     	double bit_size = encoded[vect[i].first].length();
     	cost += (frequency * bit_size);
     }

    //Print stats
    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << length << " symbols that are encoded." << endl;
    cout << "There are " << vect.size() << " distinct symbols used." << endl;
    cout << "There were " << original<< " bits in the original file." << endl;
	cout << "There were " << bits << " bits in the compressed file." << endl;
	cout << "This gives a compression ratio of " << ratio << "." << endl;
	cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;


}
