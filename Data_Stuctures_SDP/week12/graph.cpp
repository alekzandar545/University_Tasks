#pragma once
#include "graph.h"
#include <utility>
#include <vector>
#include <queue>

void Graph::copy(const Graph& other){
    cities = other.cities;
}
void Graph::free(){} //memory is managed well i think cus of the list
Graph::City* Graph::findCity(const std::string& name){}

void print(){}

Graph::Graph() = default;
Graph::Graph(const Graph& other){
    copy(other);
}
Graph::Graph(Graph&& other){
    std::swap(cities, other.cities);
}
Graph& Graph::operator=(const Graph& other){
    if(this == &other)
        return;
    copy(other);
}
Graph& Graph::operator=(Graph&& other){
    if(this == &other)
        return;
    std::swap(cities, other.cities);
}
Graph::~Graph() = default;

void Graph::addEdge(const std::string& city1, const std::string& city2, int distance){
    cities[city1]->addNeighbour(city2, distance);
    cities[city2]->addNeighbour(city1, distance);
}

int Graph::findShortestPath(const std::string& city1, const std::string& city2){
    //Write out Dijstra
    std::map<std::string, int> dist; //keeps distance to every vertex from city 1
    for (auto it = cities.begin(); it != cities.end(); it++)
    {
        // std::string name = it*;
        //dist[it*->name] = INT32_MAX;
    }
    
    
    std::map<std::string, bool> used;
    dist[city1] = 0;
    


    // for (auto it = cities.begin(); it != cities.end(); it++)
    // {
        
    // }
}

