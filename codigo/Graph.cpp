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

void Graph::showPath(int origin, int destiny) {

    list<int> path;
    int currentNode = destiny;
    while (nodes[currentNode].parent != -1) { 
        path.push_front(currentNode);
        currentNode = nodes[currentNode].parent;
    }
    if (currentNode != origin) {
        cerr << "Error: There is no path between node " << origin << " and node " << destiny << endl;
        return;
    } else path.push_front(currentNode);

    int maxCapacity = INF;
    while (!path.empty()) {
        cout << " -> " << *path.begin();
        maxCapacity = min(maxCapacity, nodes[*path.begin()].capacity);
        path.erase(path.begin());
    }
    cout << "\nMax capacity: " << maxCapacity << endl;
    return;
}

void Graph::case1_a(int origin, int destiny) {

    set<pair<int, int>> capacities;

    for (int i = 1 ; i < nodes.size() ; i++) {
        nodes[i].parent = -1;
        nodes[i].capacity = 0;
        capacities.insert(make_pair(0, i));
    }

    nodes[origin].capacity = INF;
    capacities.erase(make_pair(0, origin));
    capacities.insert(make_pair(INF, origin));

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
}

void Graph::case1_b(int origin, int destiny) {

    cout << "TODO" << endl;
}

void Graph::case1(int mode, int origin, int destiny) {

    if (origin < 1 || origin > nodes.size() - 1 || destiny < 1 || destiny > nodes.size() - 1) {
        cerr << "Error: Invalid node number. Max is " << nodes.size()-1 << endl;
        return;
    }

    switch (mode) {
        case 1:
            case1_a(origin, destiny);
            break;
        case 2:
            case1_b(origin, destiny);
            break;
        default:
            cerr << "Invalid mode for scenario 1" << endl;
            exit(-1);
            break;
    }

    showPath(origin, destiny);
}

#endif /* PROJECT_DA_PT2_GRAPH_CPP */