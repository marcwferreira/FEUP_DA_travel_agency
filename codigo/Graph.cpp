#ifndef PROJECT_DA_PT2_GRAPH_CPP
#define PROJECT_DA_PT2_GRAPH_CPP

#include "Graph.h"

Graph::Graph(int nodes, bool directed) : nodes(nodes+1), directed(directed) {
}

void Graph::clear() {
    for (Node node : nodes) node.adjacent.clear();
    nodes.clear();
}

void Graph::addNode(const Node &node, int index) {
    this->nodes[index] = node;
}

void Graph::addEdge(int origin, int destiny, int capacity, int duration) {
    if (origin < 1 || destiny > nodes.size() || origin > nodes.size() || destiny < 1) return;
        nodes[origin].adjacent.push_back({destiny, capacity, duration});
    if (!this->directed)
        nodes[destiny].adjacent.push_back({origin, capacity, duration});
}

void Graph::BFS(int origin) {

    for (int i = 1 ; i < nodes.size() ; i++) {
        nodes[i].visited = false;
        nodes[i].parent = i;
    }

    queue<int> visitedNodes = {};
    visitedNodes.push(origin);
    nodes[origin].visited = true;

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();

        for (const Edge &edge : nodes[node].adjacent) {

            int n = edge.dest;

            if (!nodes[n].visited) {
                visitedNodes.push(n);
                nodes[n].visited = true;
                nodes[n].parent = node;
            }
        }
    }
}

#endif /* PROJECT_DA_PT2_GRAPH_CPP */