//puzzlesolver.cpp
//ylw4sj
//Yannie Wu

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

//Node structure
struct Node{
	string grid;
  	Node *next;
    int distance;
};

//Helper method to print string grid as matrix
void printAsMatrix(Node* n){
    for(int i=0; i<9; i+=3){
        cout << n->grid[i] << ' ' << n->grid[i+1] << ' ' << n->grid[i+2] << endl;;     
    }
}

/**
 * @brief Generates the possible moves of a 3x3 puzzle.
 * @param n Node that contains the puzzle.
 * @return A list of Nodes that contain all the permutations.
 * @date Dec 2, 2021
 * @author Yannie Wu
 */

vector<Node*> generateNeigbors(Node* n){
	vector<Node*> nodes;

	string temp = n->grid;

	//Find location of zero
	int index = 0;
	for (int i = 0; i < temp.length(); i++){
        if(temp[i] == '0'){
            index = i;
            break;   	
    	}
    }

    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();

    int dist = n->distance + 1;

    //Swap "vertically"
    if(index >= 0 && index <= 2){
        temp = n->grid;
        temp[index] = temp[index+3];
        temp[index+3] = '0';
        n1->grid = temp;
        n1->distance = dist;
        nodes.push_back(n1);
    }

    if(index >= 3 && index <= 5){
        temp = n->grid;
        temp[index] = temp[index+3];
        temp[index+3] = '0';
        n1->grid = temp;
        n1->distance = dist;
        nodes.push_back(n1);

        temp = n->grid;
        temp[index] = temp[index-3];
        temp[index-3] = '0';
        n2->grid = temp;
        n2->distance = dist;
        nodes.push_back(n2);
    }

    if(index >= 6 && index <= 8){
        temp = n->grid;
        temp[index] = temp[index-3];
        temp[index-3] = '0';
        n1->grid = temp;
        n1->distance = dist;
        nodes.push_back(n1);
    }

    //Swap "horizontally"
    if(index == 0 || index == 3 || index == 6){
        temp = n->grid;
        temp[index] = temp[index+1];
        temp[index+1] = '0';
        n3->grid = temp;
        n3->distance = dist;
        nodes.push_back(n3);
    }

    if(index == 1 || index == 4 || index == 7){
        temp = n->grid;
        temp[index] = temp[index+1];
        temp[index+1] = '0';
        n3->grid = temp;
        n3->distance = dist;
        nodes.push_back(n3);

        temp = n->grid;
        temp[index] = temp[index-1];
        temp[index-1] = '0';
        n4->grid = temp;
        n4->distance = dist;
        nodes.push_back(n4);
    }

    if(index == 2 || index == 5 || index == 8){
        temp = n->grid;
        temp[index] = temp[index-1];
        temp[index-1] = '0';
        n3->grid = temp;
        n3->distance = dist;
        nodes.push_back(n3);
    }

    return nodes;
} 


int main(){

	cout << "Enter puzzle" << endl;

	//Input
	string all = "";
	string s;
	for(int i=0; i<9; i++){
		cin >> s;
		all += s;
	}
	

	//Create intial puzzle node
	Node* puzzle = new Node();
	puzzle->grid = all;
    puzzle->distance = 0;

  
    //Solving puzzle
    cout << "Solving puzzle" << endl;

    if(all == "123456780"){
    	cout << "0" << endl;
    	return 0;
    }
    
    
    //Check if puzzle is unsolvable
    int inv = 0;
    string inversionCheck = "";
    for(int i=0; i<all.length(); i++){
    	if(all[i] != '0'){
    		inversionCheck += all[i];
    	}
    }
    for (int i=0; i < inversionCheck.length(); i++)
        for (int j = i+1; j < inversionCheck.length(); j++)
             if (inversionCheck[j] < inversionCheck[i]){
             	inv ++;
             }
    cout << inv << endl;

   if(inv % 2 == 1) {
    	cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    //Computing number of moves;
    Node* curr;
    vector<Node*> neighbors;
    unordered_map<string, int> perms;
    queue<Node*> q;
    q.push(puzzle);
    string currGrid;

    while(!q.empty()){
        curr = q.front();
        q.pop();
        neighbors = generateNeigbors(curr);
        for(int i=0; i<neighbors.size(); i++){

            currGrid = neighbors[i]->grid;
            neighbors[i]->distance = curr->distance + 1; 

            if(currGrid!= "123456780"){       //if puzzle is not solved
                if(!perms.count(currGrid)) {  //check for duplicity
                    perms[currGrid] = 0;
                    q.push(neighbors[i]);
                }
            }
            else {                             //puzzle is solved
                cout << neighbors[i]->distance << endl;
                return 0;
            }
        }
    }

	return 0;
   

}