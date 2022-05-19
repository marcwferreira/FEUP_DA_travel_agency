#ifndef PROJECT_DA_PT2_GRAPH_CPP
#define PROJECT_DA_PT2_GRAPH_CPP

#include "Graph.h"

Graph::Graph() {}

void Graph::initialize(const string &filename) {

    fstream file;
    file.open("../input/" + filename, ios::in);
    if (!file)
    {
        cerr << "Error: file " << filename << " not found" << endl;
        return;
    }
    if (file.is_open())
    {   
        string numNodes, InitialNode, DestinyNode, capacity, duration;
        getline(file, numNodes, ' ');
        this->nodes = vector<Node>(stoi(numNodes)+1);
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, InitialNode, ' ');
            getline(file, DestinyNode, ' ');
            getline(file, capacity, ' ');
            getline(file, duration);
            try {
                this->addEdge(stoi(InitialNode), stoi(DestinyNode), stoi(capacity), stoi(duration));
            } catch (exception e) {
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

void Graph::showPath(int begin, int end) {

    list<int> path;
    int currentNode = end;
    while (nodes[currentNode].parent != -1) { 
        path.push_front(currentNode);
        currentNode = nodes[currentNode].parent;
    }
    if (currentNode != begin) {
        cerr << "There is no path between node " << begin << " and node " << end << endl;
        return;
    } else path.push_front(currentNode);

    while (!path.empty()) {
        cout << "Node: " << *path.begin() << endl;
        path.erase(path.begin());
    }
    return;
}

void Graph::case1(int mode, int begin, int end) {

    // TODO: verificar begin e end && criar uma função para cada mode e fazer aqui o switch

    // parte "a" do case 1
    set<pair<int, int>> capacities;

    for (int i = 1 ; i < nodes.size() ; i++) {
        nodes[i].parent = -1;
        nodes[i].capacity = 0;
        capacities.insert(make_pair(0, i));
    }

    nodes[begin].capacity = INF;
    capacities.erase(make_pair(0, begin));
    capacities.insert(make_pair(INF, begin));

    while (!capacities.empty()) {

        int currentNodeIndex = capacities.begin()->second;
        int currentNodeCapacity = capacities.begin()->first;
        capacities.erase(capacities.begin());

        for (Edge e : nodes[currentNodeIndex].adjacent) {
            if (min(currentNodeCapacity, e.capacity) > nodes[e.dest].capacity) {
                int oldCapacity = nodes[e.dest].capacity;
                nodes[e.dest].capacity = min(currentNodeCapacity, e.capacity);
                nodes[e.dest].parent = currentNodeIndex;
                capacities.erase(make_pair(oldCapacity, e.dest));
                capacities.insert(make_pair(nodes[e.dest].capacity, e.dest));
            }
        }    
    }

    showPath(begin, end);
}

#endif /* PROJECT_DA_PT2_GRAPH_CPP */