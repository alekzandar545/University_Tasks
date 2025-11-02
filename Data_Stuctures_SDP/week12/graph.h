#pragma once
#include <iostream>
#include <map>
#include <list>

class Graph{
private:
    struct City
    {
        std::string name;
        std::map<std::string, int> neighbours;

        City(std::string name) : name(name){}
        void addNeighbour(std::string name, int distance){
            neighbours[name] = distance;
        }
    };
    std::map<std::string, City*> cities;

    void copy(const Graph& other);
    void free();
    City* findCity(const std::string& name);

    void print();
public:
    Graph();
    Graph(const Graph& other);
    Graph(Graph&& other);
    Graph& operator=(const Graph& other);
    Graph& operator=(Graph&& other);
    ~Graph();

    void addEdge(const std::string& city1, const std::string& city2, int distance);
    int findShortestPath(const std::string& city1, const std::string& city2);


};