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

void Graph::reset() {
    for (int i = 1 ; i < nodes.size() ; i++) {
        nodes[i].parent = -1;
        nodes[i].capacity = 0;
        nodes[i].visited = false;
    }
}

void Graph::addNode(const Node &node, int index) {
    this->nodes[index] = node;
}

bool Graph::isValid(int node) {
    return node > 0 && node < nodes.size();
}

void Graph::addEdge(int origin, int destiny, int capacity, int duration) {
    if (!isValid(origin) || !isValid(destiny)) return;
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
    int transbordos = 0;
    cout << *path.begin();
    path.erase(path.begin());
    while (!path.empty()) {
        cout << " <--(" << nodes[*path.begin()].capacity << ")--> " << *path.begin();
        maxCapacity = min(maxCapacity, nodes[*path.begin()].capacity);
        path.erase(path.begin());
        transbordos++;
    }
    cout << "\nMax capacity: " << maxCapacity << endl;
    cout << "Transbordos: " << transbordos << endl;
}

//CASE 1

void Graph::case1_a(int origin, int destiny) {

    cout << "Maximizar o número de pessoas a viajar" << endl;

    set<pair<int, int>> capacities;

    reset();
    for (int i = 1 ; i < nodes.size() ; i++) {
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
    showPath(origin, destiny);
}

void Graph::case1_b(int origin, int destiny) {

    cout << "Minimizar o número de transbordos" << endl;

    reset();
    queue<int> visitedNodes = {};
    visitedNodes.push(origin);              
    nodes[origin].visited = true;           

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();          

        for (Edge e : nodes[node].adjacent) { 
            int n = e.dest;              
            if (!nodes[n].visited) {               
                visitedNodes.push(n);           
                nodes[n].visited = true; 
                nodes[n].capacity = e.capacity;   
                nodes[n].parent = node;  
            }
        }
    }
    showPath(origin, destiny);
}

void Graph::case1(int mode, int origin, int destiny) {

    if (!isValid(origin) || !isValid(destiny)) {
        cerr << "Error: Invalid node number. Max is " << nodes.size()-1 << endl;
        return;
    }

    switch (mode) {
        case 1:
            case1_a(origin, destiny);
            break;
        case 2:
            case1_a(origin, destiny);
            case1_b(origin, destiny);
            break;
        default:
            cerr << "Invalid mode for scenario 1" << endl;
            exit(-1);
            break;
    }
}

void Graph::case2(int mode, int origin, int destiny, int groupSize) {

    if (!isValid(origin) || !isValid(destiny)) {
        cerr << "Error: Invalid node number. Max is " << nodes.size()-1 << endl;
        return;
    }

    switch (mode) {
        case 3:
            case2_a(origin, destiny, groupSize);
            break;
        case 4:
            cout << "TODO" << endl;
            break;
        case 5:
            cout << "TODO" << endl;
            break;
        case 6:
            cout << "TODO" << endl;
            break;
        case 7:
            cout << "TODO" << endl;
            break;
        default:
            cerr << "Invalid mode for scenario 2" << endl;
            exit(-1);
            break;
    }
}

//CASE 2

void Graph::case2_a(int origin, int destiny, int groupSize) {
    
    list<list<int>> pathList;
    int remainderSize = groupSize;

    while (remainderSize>0){ 

        int capacity = INF;

        reset();
        queue<int> visitedNodes = {};
        visitedNodes.push(origin);              
        nodes[origin].visited = true;           

        while (!visitedNodes.empty()) {

            int node = visitedNodes.front();
            visitedNodes.pop();          

            for (Edge e : nodes[node].adjacent) { 
                int n = e.dest;              
                if (!nodes[n].visited && e.capacity > 0) {           
                    visitedNodes.push(n);           
                    nodes[n].visited = true; 
                    nodes[n].capacity = e.capacity;   
                    nodes[n].parent = node;  
                    capacity = min(capacity, e.capacity);
                }
            }
        }

        list<int> path;

        int currentNode = destiny;
        while (nodes[currentNode].parent != -1) { 
            path.push_front(currentNode);

            for (Edge &e : nodes[nodes[currentNode].parent].adjacent){
                if (e.dest == currentNode) {
                    e.capacity -= capacity;
                }
            }

            currentNode = nodes[currentNode].parent;
        }
        if (currentNode != origin) {
            cerr << "Error: There is no path between node " << origin << " and node " << destiny << endl;
            return;
        } else path.push_front(currentNode);
        pathList.push_back(path);
        remainderSize -= capacity;

        cout << *path.begin();
        path.erase(path.begin());
        while (!path.empty()) {
            cout << " <---> " << *path.begin();
            path.erase(path.begin());
        }
        cout << "  Capacity: " << capacity << endl;

    }

    /*
    for(list<int> path1: pathList){
        cout << *path1.begin();
        path1.erase(path1.begin());
        while (!path1.empty()) {
            cout << *path1.begin();
            path1.erase(path1.begin());
        }
    }
    */

}

#endif /* PROJECT_DA_PT2_GRAPH_CPP */