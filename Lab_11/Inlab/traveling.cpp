//traveling.cpp
//ylw4sj
//Yannie Wu

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * @brief Helper method to calculate n!
 * @param n Value to be calculated as a factorial
 * @return Returns n!
 * @date November 30, 2021
 * @test Input the world height, width, number of cities, random seed, and cities to visit in the command line
 */
int fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    string startCity = dests[0];

    //remove start city and sort
    dests.erase(remove(dests.begin(), dests.end(), startCity), dests.end()); 
    sort(dests.begin(), dests.end());

    //Cycle through permutations and find best path
    vector<string> bestPath = dests;
    float bestDistance = computeDistance(me, startCity, dests);

    
    //Check for base case
    if(cities_to_visit == 1){
        cout << "Minimum path has distance " << bestDistance << ": ";
        cout << startCity << " -> " << dests[0] << " -> " << startCity << endl;
    }
   
    else{
        //Do calculations
        int numPerm = fact(dests.size());
        while(next_permutation(dests.begin(), dests.end())){
            float path = computeDistance(me, startCity, dests);
            if(path<bestDistance){
                bestDistance = path;
                bestPath = dests;
            }
            //next_permutation(dests.begin(), dests.end());               
        }

        //Print out answer
        cout << "Minimum path has distance " << bestDistance << ": ";
            printRoute(startCity, bestPath);
        cout << endl;
        }

    return 0;

}

/**
 * @brief Method that will compute the full distance of the cycle that starts 
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 * @param me A Middle Earth object.
 * @param start The starting city.
 * @param dests A list of destinations to travel to.
 * @return The total distance to travel to the destinations in the list in that order.
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    int size = dests.size()-1;
    float totalDistance = me.getDistance(start, dests[0]) + me.getDistance(dests[size], start);
    for(int i=0; i<size; i++){
        totalDistance += me.getDistance(dests[i], dests[i+1]);
    }

    return totalDistance;
}


/**
 * @brief Method that will print the entire route, starting and ending at the
 * 'start' parameter.
 * @param start The starting city.
 * @param dests A list of destinations to travel to
 * @return Prints out the route
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    cout << start << " -> ";
    for(int i=0; i<dests.size(); i++){
        cout << dests[i] << " -> ";
    }
    cout << start;
}
