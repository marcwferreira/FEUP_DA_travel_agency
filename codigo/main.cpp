#include <iostream>
#include "Graph.h"

int main(int argc, char* argv[]) {

    std::cout << "Hello world!" << std::endl;

    Graph graph = Graph();
    graph.initialize(argv[1]);

    graph.BFS(1);

    return 0;
}