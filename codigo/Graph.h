#ifndef PROJECT_DA_PT2_GRAPH_H
#define PROJECT_DA_PT2_GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "utils.h"
#include <stdexcept>
#include <limits>
#include <typeinfo>       // operator typeid
#include <exception>

using namespace std;

/**
 * Class that represents a Graph and its entire structure
 */
class Graph {

    private:

        /**
         * @var nodes - a vector containing Node type struct that includes all nodes of current Graph
         */
        vector<Node> nodes;

        /**
         * Function that adds a new Node to the graph
         * Time Complexity: O(1)
         * @param node - Node struct that contains all characteristics of the stop
         * @param index - an integer value that represents the Stop index in vector
         */
        void addNode(const Node &node, int index);

        /**
         * Function that adds an Edge between two nodes
         * Time Complexity: O(1)
         * @param origin - an integer value representing the index of origin Node
         * @param destiny - an integer value representing the index of destiny Node
         * @param capacity -  an integer value representing capacity of current Edge
         * @param duration - an integer value representing duration of traveling to one node to another
         */
        void addEdge(int origin, int destiny, int capacity, int duration);
        
    public:

        /**
         * Main constructor of the class Graph
         */
        Graph();
        
        /**
         * @brief 
         * 
         * @param filename 
         */
        void initialize(const string &filename);

        /**
         * Function that clears all Nodes
         * Time Complexity: O(V), which V is the number of nodes
         */
        void clear();

        /**
         * Breadth-first search to determinate the distance, in nodes, between two stops
         * Time Complexity: O(V + E), which V is the number of Nodes and E is the number of edges
         * @param origin - index of origin stop
         */
        void BFS(int origin);
};

#endif /* PROJECT_DA_PT2_GRAPH_H */