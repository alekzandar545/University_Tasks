#include <iostream>
#include "graph.hpp"

int main(){
    std::ifstream stream("graph.txt");
    Graph g;
    g.deserialize(stream);
    std::cout << g.findComponents() << '\n';
    std::vector<int> dist = g.scuffedDijstra(3);
    for (size_t i = 0; i < dist.size(); i++)
    {
        std::cout << dist[i] << ' ';
    }
        
}