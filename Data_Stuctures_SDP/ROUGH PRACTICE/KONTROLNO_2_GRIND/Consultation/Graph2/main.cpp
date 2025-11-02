#include <iostream>
#include <fstream>
#include "graph.hpp"

int main(){
    std::ifstream s1("graph1.txt");
    std::ifstream s2("graph2.txt");
    Graph g1, g2;
    g1.deserialize(s1);
    g2.deserialize(s2);

    std::cout << std::boolalpha << g1.hasEulerianPath(2,2) << ' ' << g2.hasEulerianPath(0,0);
}