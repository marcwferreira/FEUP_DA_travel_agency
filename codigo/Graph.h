#ifndef PROJECT_DA_PT2_GRAPH_H
#define PROJECT_DA_PT2_GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <string>
#include "Utils.h"
#include <stdexcept>
#include <limits>
#include <typeinfo>
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

        /**
         * Function that clears all Nodes
         * Time Complexity: O(V), which V is the number of nodes
         */
        void reset();
        
        /**
         * @brief 
         * 
         * @param node 
         * @return true 
         * @return false 
         */
        bool isValid(int node);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny 
         */
        void showPath(int origin, int destiny);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny 
         */
        void case1_a(int origin, int destiny);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny 
         */
        void case1_b(int origin, int destiny);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny
         * @param groupSize 
         */
        void case2_a(int origin, int destiny, int groupSize);

         /**
         * @brief 
         * 
         * @param origin 
         * @param destiny
         * @param pathList
         * @param oldGroupSize
         * @param newGroupSize
         * @param groupSize 
         */
        void case2_b(int origin, int destiny, vector<vector<int>> pathList, int oldGroupSize, int newGroupSize);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny
         */
        void case2_c(int origin, int destiny);

        /**
         * @brief 
         * 
         * @param origin 
         * @param destiny
         * @param pathList
         * @param oldGroupSize
         * @param newGroupSize
         * @param groupSize 
         */
        void case2_d(int origin, int destiny, vector<vector<int>> pathList);

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
         * @brief 
         * 
         * @param mode 
         * @param origin 
         * @param destiny 
         */
        void case1(int mode, int origin, int destiny);

        /**
         * @brief 
         * 
         * @param mode 
         * @param origin 
         * @param destiny 
         * @param groupSize
         */
        void case2(int mode, int origin, int destiny, int groupSize);


};

#endif /* PROJECT_DA_PT2_GRAPH_H */