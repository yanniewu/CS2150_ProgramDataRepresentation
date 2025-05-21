#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp


class MiddleEarth {
public:
    /**
     * @brief A constructor that builds a MiddleEarth object
     * @param xsize Maximum x-coordinate of the city.
     * @param ysize Maximum y-coordinate of the city.
     * @param num_cities The number of cities to be included in the map.
     * @param seed Used to set up the random number generator.
     * @date November 30, 2021
     */
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
   
    /**
     * @brief A method that prints all the cities of the world
     */
    void print();
    
    /**
     * @brief A method that prints a tab-separated table of the distances.
     * 
     * Can be loaded into Excel or a similar program.
     */
    void printTable();
    
    /**
     * @brief A method that computes the distance between the two passed cities.
     * @param city1 The first city.
     * @param city2 The second city.
     * @return A decimal value of the distance between the two passed cities
     */
    float getDistance(const string& city1, const string& city2);

    /**
     * @brief A method that creates a list of cities to travel to
     * @param length The number of cities to travel to
     * @return A vector of strings of cities
     */ 
    vector<string> getItinerary(unsigned int length);

    /**
     * Variables that hold the number of cities and the size of the world
     */
    int num_city_names, xsize, ysize;

    /**
     * Map that contains the names of the cities and their x/y coordinate
     */
    unordered_map<string, float> xpos, ypos;

    /**
     * Vector of cities
     */
    vector<string> cities;

    /**
     * Map of the distances of the city
     */
    unordered_map<string, unordered_map<string, float> > distances;

    /**
     * Random number generator
     */
    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
