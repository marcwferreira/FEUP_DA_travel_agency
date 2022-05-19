#include <iostream>
#include "Graph.h"
using namespace std;

void usage() {
    cout << "\nUsage: /proj2 <CASE> <OPTION> <GRAPH>\n" << endl;
    cout << "       <CASE>" << endl;
    cout << "          1: Não há separação do grupo" << endl;
    cout << "          2: Pode haver separação do grupo" << endl;
    cout << "       <OPTION>" << endl;
    cout << "          1: tal" << endl;
    cout << "          2: tal" << endl;
    cout << "          3: tal" << endl;
    cout << "          4: tal" << endl;
    cout << "          5: tal" << endl;
    cout << "          6: tal" << endl;
    cout << "          7: tal" << endl;
    cout << "       <GRAPH>" << endl;
    cout << "          Nome do ficheiro da pasta input que descreve o grafo\n" << endl;
}

void exists(const string &fileName)
{
  fstream file;
  file.open("../input/" + fileName, ios::in);
  if (!file.is_open())
  {
    cerr << "Error: file '" << fileName << "' not found" << endl;
    exit(-1);
  }
  file.close();
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        if (argv[1] != NULL && !strcmp(argv[1], "--help")) {  
            usage();
        } else {
            cerr << "Error: invalid arguments\nPlease see ./proj2 --help" << endl;
        }
        return 0;
    }

    exists(argv[3]);

    Graph graph = Graph();
    graph.initialize(argv[3]);

    switch (stoi(argv[1])) {
        case 1:
            cout << "#TODO: Case 1" << endl;
            break;
        case 2:
            cout << "#TODO: Case 2" << endl;
            break;
        default:
            cerr << "Error: invalid case scenario" << endl;
            exit(-1);
            break;
    }

    // test graph
    graph.BFS(1);

    return 0;
}