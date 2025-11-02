#include "graph.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream in("graph1.txt");
    Graph g;
    g.deserialise(in);
    std::vector<string> a;
    a = g.DFS("A");
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    Graph::NodesList resDFS = g.DFS("A");
    Graph::NodesList resBFS = g.BFS("A");
    Graph::DistancesType resDijkstra= g.Dijkstra("A");
    for(string s:resDFS)
        cout<<s<<" ";
    cout<<"\n";
    for(string s:resBFS)
        cout<<s<<" ";
    for(pair<pair<string,string>,int> dist:resDijkstra)
        cout<<dist.first.first<<" - "<< dist.first.second<<"    "<<dist.second<<endl;

    (g.Prim()).serialise(cout);
}