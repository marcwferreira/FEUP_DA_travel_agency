#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition of the largest number used in class bellow
 */
#define INF (INT_MAX/2)

/**
 * Struct that groups all characteristics of the edge that separates two nodes
 */
struct Edge {

    /**
     * @var dest - an integer value that represents the destination of current edge, based on node's index
     */
    int dest;
    
    /**
     * @var capacity - an integer value that represents the capacity of the vehicle on this path
     */
    int capacity;

    /**
     * @var duration - an integer value that represents the duration of traveling to destination node
     */
    int duration;
};

/**
 * Struct that represents a Stop in Porto
 */
struct Node {

    /**
     * @var adjacent - a list of Edges containing all possible paths from the current node
     */
    std::list<Edge> adjacent;

    /**
     * @var visited - a boolean attribute that indicates if the stop is active
     */
    bool visited;

    /**
     * @var parent - an integer value represents previous node index
     */
    int parent;

    int capacity;
};

bool readGivenPaths(vector<vector<int>> *paths, int *groupSize);

#endif /* UTILS_H */