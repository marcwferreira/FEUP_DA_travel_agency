#ifndef PROJECT_DA_PT2_GRAPH_CPP
#define PROJECT_DA_PT2_GRAPH_CPP

#include "Graph.h"

using namespace std;

Graph::Graph() {}

void Graph::initialize(const string &filename) {

    fstream file;
    file.open("../input/" + filename, ios::in);
    if (!file)
    {
        cerr << "Error: file " << filename << " not found" << endl;
        return; //???
    }
    if (file.is_open())
    {   
        string numNodes;
        string InitialNode, DestinyNode, capacity, duration;
        getline(file, numNodes, ' ');
        try{
        this->nodes = vector<Node>(stoi(numNodes)+1);
        }
        catch (exception e){
            return;
        }
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, InitialNode, ' ');
            getline(file, DestinyNode, ' ');
            getline(file, capacity, ' ');
            getline(file, duration);
            try {
                this->addEdge(stoi(InitialNode), stoi(DestinyNode), stoi(capacity), stoi(duration));
            }
            catch (exception e) {
                return;
            }
        }
        file.close();
    }
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

        cout << node << endl;

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