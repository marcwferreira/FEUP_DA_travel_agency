#ifndef PROJECT_DA_PT2_GRAPH_H
#define PROJECT_DA_PT2_GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <queue>
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
    list<Edge> adjacent;

    /**
     * @var visited - a boolean attribute that indicates if the stop is active
     */
    bool visited;

    /**
     * @var parent - an integer value represents previous node index
     */
    int parent;
};

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
         * @var directed - a boolean flag representing if the graph is directed or not
         */
        bool directed;

    public:

        /**
         * Main constructor of the class Graph
         * @param nodes - an integer number that represents the number of nodes that graph must have
         * @param directed - a boolean flag that represents if the graph is directed or not
         */
        explicit Graph(int nodes, bool directed);

        /**
         * Function that clears all Nodes
         * Time Complexity: O(V), which V is the number of nodes
         */
        void clear();

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
         * Breadth-first search to determinate the distance, in nodes, between two stops
         * Time Complexity: O(V + E), which V is the number of Nodes and E is the number of edges
         * @param origin - index of origin stop
         */
        void BFS(int origin);
};

#endif /* PROJECT_DA_PT2_GRAPH_H */