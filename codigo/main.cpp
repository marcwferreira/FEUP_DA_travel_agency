#include <iostream>
#include "Graph.h"
using namespace std;

void usage() {
    cout << "\nUsage: /proj2 <CASE> <OPTION> <GRAPH> <ORIGIN> <DESTINY> [GROUP SIZE]\n" << endl;
    cout << "       <CASE>" << endl;
    cout << "          1: Não há separação do grupo" << endl;
    cout << "          2: Pode haver separação do grupo" << endl;
    cout << "       <OPTION>" << endl;
    cout << "          [1] 1: Maximização do tamanho do grupo" << endl;
    cout << "          [1] 2: Minimização dos transbordos vs. maximização do tamanho do grupo" << endl;
    cout << endl;
    cout << "          [2] 1: Determinar um encaminhamento para um grupo de um determinado tamanho [GROUP SIZE]" << endl;
    cout << "          [2] 2: Corrigir o encaminhamento anterior de modo a aumentar o tamanho do grupo transportado [GROUP SIZE]" << endl;
    cout << "          [2] 3: Determinar a dimensão máxima do grupo e um encaminhamento" << endl;
    cout << "          [2] 4: Tempo mínimo para todo o grupo chegar ao destino" << endl;
    cout << "          [2] 5: Tempo máximo de espera entre conexões" << endl;
    cout << "       <GRAPH>" << endl;
    cout << "          Nome do ficheiro da pasta input que descreve o grafo" << endl;
    cout << "       <ORIGIN>" << endl;
    cout << "          Nó de origem do caminho" << endl;
    cout << "       <DESTINY>" << endl;
    cout << "          Nó de destino do caminho" << endl;
    cout << "       [GROUP SIZE]" << endl;
    cout << "          Tamanho do grupo desejado\n" << endl;
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

    if (argc < 6 || argc > 7) {
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
            if(argc != 6){
                cerr << "Error: Invalid inputs" << endl;
            }
            else{
                 graph.case1(stoi(argv[2]), stoi(argv[4]), stoi(argv[5]));
            }
            break;
        case 2:
            if (stoi(argv[2]) == 1 || stoi(argv[2]) == 2){
                if( argc != 7) cerr << "Error: Invalid inputs" << endl;
                else{
                    graph.case2(stoi(argv[2]), stoi(argv[4]), stoi(argv[5]), stoi(argv[6]));
                }
            }
            else{
                if( argc != 6) cerr << "Error: Invalid inputs" << endl;
                else{
                    graph.case2(stoi(argv[2]), stoi(argv[4]), stoi(argv[5]));
                }
            }
            break;
        default:
            cerr << "Error: invalid case scenario" << endl;
            exit(-1);
            break;
    }

    return 0;
}