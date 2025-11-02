#include <fstream>
#include <iostream>
#include "graph.hpp"

int main(){
    std::ifstream in("graph2.txt");
    Graph g;
    g.deserialise(in);
    //g.serialise(std::cout);
    // std::vector<int> dfsPath = g.DFS(1);
    std::vector<int> bfsPath = g.BFS(1);
    std::vector<int> distances = g.Dijkstra(1);
    Graph g2 = g.Prim();
    g2.serialise(std::cout);
    //std::vector<int> dfsPath = g2.DFS(1);
    // std::cout << "---------------------------\n";
    // for (size_t i = 1; i < dfsPath.size(); i++)
    // {
    //     std::cout << i << ' ' << dfsPath[i] << '\n';
    // }
    
}