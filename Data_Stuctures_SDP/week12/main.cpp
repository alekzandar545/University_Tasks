#include <iostream>
#include "graph.h"

int main(){
    unsigned n;
    std::cin >> n;

    Graph graph;

    for (size_t i = 0; i < n; i++)
    {
        std::string city1, city2;
        int distance;
        std::cin >> city1 >> city2 >> distance;

        graph.addEdge(city1, city2, distance);
    }
    
}