#include <iostream>
#include "Graph.h"
using namespace std;

void usage() {
    cout << "\nUsage: /proj2 <CASE> <OPTION> <GRAPH> <ORIGIN> <DESTINY>\n" << endl;
    cout << "       <CASE>" << endl;
    cout << "          1: Não há separação do grupo" << endl;
    cout << "          2: Pode haver separação do grupo" << endl;
    cout << "       <OPTION>" << endl;
    cout << "          1: Maximização do tamanho do grupo" << endl;
    cout << "          2: Minimização dos transbordos vs. maximização do tamanho do grupo" << endl;
    cout << "          3: tal" << endl;
    cout << "          4: tal" << endl;
    cout << "          5: tal" << endl;
    cout << "          6: tal" << endl;
    cout << "          7: tal" << endl;
    cout << "       <GRAPH>" << endl;
    cout << "          Nome do ficheiro da pasta input que descreve o grafo" << endl;
    cout << "       <ORIGIN>" << endl;
    cout << "          Nó de origem do caminho" << endl;
    cout << "       <DESTINY>" << endl;
    cout << "          Nó de destino do caminho\n" << endl;
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

    if (argc != 7) {
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
            try {
                graph.case1(stoi(argv[2]), stoi(argv[4]), stoi(argv[5]));
            } catch (const exception &e) { cerr << "Error: Invalid inputs" << endl; }
            break;
        case 2:
            try {
                graph.case2_1(stoi(argv[4]), stoi(argv[5]), stoi(argv[6]));
            } catch (const exception &e) { cerr << "Error: Invalid inputs" << endl; }
            break;
        default:
            cerr << "Error: invalid case scenario" << endl;
            exit(-1);
            break;
    }

    return 0;
}