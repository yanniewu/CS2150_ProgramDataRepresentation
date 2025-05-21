//Yannie Wu
//ylw4sj
//wordPuzzle.cpp

#include <iostream>
#include <string> 
#include <fstream>
#include <unordered_set>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


int main(int argc, char **argv){

	//Reading in dictionary to find number of elements
	ifstream dictFile(argv[1]);
	int size = 0;
	string line = "";

	if (dictFile.is_open()){
    	while (getline(dictFile, line)){  //Finding number of elements
      	size++;
    	}
    	dictFile.close();
  	}
  	else cout << "Unable to count number of elements" << endl;

  	//Creating hashtable
  	if(!checkprime(size)){
  		size = getNextPrime(size);
  	}
  	hashTable dictionary(size);


	//Reading in dictionary and inserting to hashtable
	string word = "";

	ifstream dictFile2(argv[1]);
	if (dictFile2.is_open()){
    	while (getline(dictFile2, word)){  //Inserting to hashtable
      	dictionary.insert(word);
    	}
    	dictFile2.close();
  	}

  	else cout << "Unable to open file" << endl;


  	//Reading in grid
   	string num = "";
  	int rows = 0;
  	int columns = 0;

  	ifstream gridFile(argv[2]);
  	if (gridFile.is_open()){
    	for(int i=0; getline(gridFile, num) &&  i <3; i++){  //Finding # rows and columns
    		if(i==0){
    			rows = stoi(num);
    		}
    		if(i==1){
    			columns = stoi(num);
    		}
    	}
    gridFile.close();
    }

  	else cout << "Unable to open file" << endl;


  	//Creating word search grid
  	bool result = readInGrid(argv[2], rows, columns);
  	
  	string direction[8] = {"N ", "NE", "E ", "SE", "S ", "SW", "W ", "NW"};
  	int wordCount = 0;
  	string found = "";

  	//Timer
  	timer time;
  	time.start();

  	//Searching every combo of row, column, direction, and length
  	if(result){
  		for(int currRow=0; currRow<rows; currRow++){
  			for(int currCol=0; currCol<columns; currCol++){
  				for(int currDir=0; currDir<8; currDir++){
  					for(int length=3; length<=22; length++){
  						if(getWordInGrid(currRow, currCol, currDir, length, rows, columns).length()==length){
  							if(dictionary.check(getWordInGrid(currRow, currCol, currDir, length, rows, columns))){
  								cout << direction[currDir] << "(" << currRow << ", " << currCol << "):  " << getWordInGrid(currRow, currCol, currDir, length, rows, columns) << endl;
  								wordCount++;
  							}
  						}
  					}
  				}
  			}
  		}
  	}

  	cout << wordCount << " words found" << endl;

  	time.stop();
  	//cout << time.getTime()<< endl;


}


