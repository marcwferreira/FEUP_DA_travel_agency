/*! \mainpage DA Delivery System - Calculating and organizing the best way of delivering packages using the least amount of resources possible
 *
 * This project uses Alrogithm conception studies in order to calculate the best way of organinzing deliveries for a ficticional company with the goal of 
 * delivering the maximum amount of packages in a day using the least amount of resources, specified by the different functions provided.
 *
 * This work was done within the scope of the Algorithms Development curricular course,
 * and aimed at deepening the knowledge about conception of algorithms and dynamic programming.
 *
 * With this simple program you can select load a list of packages to be delivered and a list of trucks, in which
 * after you select from 3 possible cases:
 *  - Least amount of trucks 
 *  - Maximize profit (even in detriment of customer satisfaction by an small amount)
 *  - Maximize number of express deliveries
 *
 * @author Fábio Araújo de Sá, Marcos William Ferreira Pinto
 *
 * @date 31/05/2022
 */

#include <iostream>
#include "Graph.h"
using namespace std;

void usage() {
    cout << "\nUsage: /proj2 <CASE> <OPTION> <GRAPH> <ORIGIN> <DESTINATION> [GROUP SIZE]\n" << endl;
    cout << "       <CASE>" << endl;
    cout << "          1: Without group division between paths" << endl;
    cout << "          2: With group division between paths" << endl;
    cout << "       <OPTION>" << endl;
    cout << "          [1] 1: Max size of a group traveling" << endl;
    cout << "          [1] 2: Minimization number of bus changes vs. maximization of group size" << endl;
    cout << endl;
    cout << "          [2] 1: Find travel routes for a group of a determined size [GROUP SIZE]" << endl;
    cout << "          [2] 2: Correct travel routes in case group size increases (number of bus changes can go up) [GROUP SIZE]" << endl;
    cout << "          [2] 3: Calculate the max group size and trabel routes between origin and destination" << endl;
    cout << "          [2] 4: Minimum amount of time for the whole group to arrive at destination" << endl;
    cout << "          [2] 5: Max amount of time a subset of the group may wait between connections (bus changes)" << endl;
    cout << "       <GRAPH>" << endl;
    cout << "          Name of the file (inside input folder) that describes the graph" << endl;
    cout << "       <ORIGIN>" << endl;
    cout << "          Path's origin node " << endl;
    cout << "       <DESTINY>" << endl;
    cout << "          Path's destination node" << endl;
    cout << "       [GROUP SIZE]" << endl;
    cout << "          Desired group size\n" << endl;
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