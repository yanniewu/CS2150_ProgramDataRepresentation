//topological.cpp
//Yannie Wu
//ylw4sj


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

/**
 * *@brief Sorts a set of vertices by topolgical order.
 * 
 * This function uses an adjacency list to sort the vertices.
 * 
 * @return A valid topological sort of the vertices, each separated by one space, and all on one line.
 * @test Create a file with each line containing two vertex names, separated by a single space; the edge is directed from the first to the second listed vertex name on a given line.
 * The end of the file should be signified with "0 0." Run the code with the file name as a command-line parameter.
 * @warning Do not use a space in your file unless it is to separate the first and second vertex. Vertexes are case sensitive.
 * 
 */

int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    //open the file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    //Read file and put into array
    vector<string> vect;
    while (file){
      	string word;
        file >> word;

        //End of file reached
        if (word == "0") {
            break;
        }

        vect.push_back(word);   
    }
    file.close();


    //Format array into pairs
    vector<pair <string, string> > pairs;
    for(int i=0; i<vect.size(); i+=2){
    	pairs.push_back(make_pair(vect[i], vect[i+1]));
    }

 	
 	//Make adjacency list	
 	unordered_map<string, vector<string> > adjList;
    for(int i=0; i<vect.size(); i++){		//Create map with no repeats
    	string word = vect[i];
    	if(!adjList.count(word)){
    		vector<string> adj;
    		adjList[word] = adj;
    	}
    }

    for(int i=0; i<pairs.size(); i++){		//Fill in adjacency for each course
    	string firstWord = pairs[i].first;
    	string secondWord = pairs[i].second;
    	
    	vector<string> adj = adjList[firstWord];
    	adj.push_back(secondWord);
    		adjList[firstWord] = adj;
    }


   	//Calculate indegree
    unordered_map<string, int> indegree;

    //Initially set all indegrees to zero Uneccesary??
    /*for (auto it = adjList.begin(); it != adjList.end(); it++){
    	indegree[it->first] = 0;
    }*/
	for (auto it = adjList.begin(); it != adjList.end(); it++){
		string key = it->first;
		for(int i=0; i<pairs.size(); i++){
			if(pairs[i].second == key){
				indegree[key] = indegree[key] + 1;
			}
    	}
	}
	

    //Topological sort
	queue<string> q;
	string v;
	vector<string> w;
	for (auto it = adjList.begin(); it != adjList.end(); it++){
		v = it->first;
		if(indegree[v] == 0){
			q.push(v);
		}
	}
	while(!q.empty()){
		v = q.front();
		q.pop();
		cout << v << " ";
		w = adjList[v];
		for(int i=0; i<w.size(); i++){
			string s = w[i];
			indegree[s] = indegree[s] - 1;
			if(indegree[s] == 0){
				q.push(s);
			}
		}
	}

/*
    //Print adjacency list
    cout << "Adjanceny List:" << endl;
    for (auto it = adjList.begin(); it != adjList.end(); it++){
    	cout << it->first << ": ";
    	vector<string> v = it->second;
    	for(int i=0; i<v.size(); i++){
    		cout << v[i] << " ";
    	}
    	cout << endl;
	}
	cout << endl;
	cout << "Indegree: " << endl;
	for (auto it = adjList.begin(); it != adjList.end(); it++){
    	cout << it->first << ": ";
    	cout << indegree[it->first] << endl;
	}*/
    

 }
