#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

class Graph{
private:
    struct Edge{
        int from, to, weight;
        Edge() : from(0), to(0), weight(0){}
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight){}
    };
    //za tazi zadacha malko po razlichen nachin za predstavqne na datata
    int vertices = 0;
    std::vector<Edge> data;

    void copy(const Graph& other){data = other.data;}
public:
    Graph() = default; //used when reading from file
    Graph(int vertices) : vertices(vertices) {} //used when adding stuff during runtime
    ~Graph() = default; //vector destructor W
    Graph(const Graph& other){copy(other);}
    Graph(Graph&& other) noexcept{std::swap(data,other.data);}
    Graph& operator=(const Graph& other){
        if(this != &other){
            data = other.data;
        }
        return *this;
    }
    Graph& operator=(Graph&& other) noexcept{
        if(this != &other){
            std::swap(data,other.data);
        }
        return *this;
    }
    
    void addEdge(int from, int to, int weight){
        data.push_back({from,to,weight});
    }

    void deserialize(std::ifstream& stream){
        int vertices, edges;
        stream >> vertices >> edges;

        this->vertices = vertices;
        data.reserve(edges); //reserve is better cus i havent pushed in the elements yet ;3
        
        for (size_t i = 0; i < edges; i++)
        {
            int from, to, weight;
            stream >> from >> to >> weight;
            addEdge(from,to,weight);
        }
        
    }
    bool isConnected(){
        //1. create my own list of eges
        std::vector<std::vector<Edge>> vertexEdges(vertices);
        for (size_t i = 0; i < data.size(); i++)
        {
            int from = data[i].from;
            int to = data[i].to;
            int weight = data[i].weight;
            vertexEdges[from].push_back({from, to, weight});
        }
        //now we do a bfs
        std::queue<int> q;
        std::vector<bool> used(vertices, false);
        used[0] = true;
        q.push(0);
        int traversedCount = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            used[curr] = true;
            traversedCount++;

            for (size_t i = 0; i < vertexEdges[curr].size(); i++)
            {
                int destination = vertexEdges[curr][i].to;
                if(!used[destination]){
                    q.push(destination);
                }
            }
            
        }
        return traversedCount == vertices;
    }

    Graph reverse(){
        Graph g(vertices);
        for (size_t i = 0; i < data.size(); i++)
        {
            g.addEdge(data[i].to, data[i].from, data[i].weight); //reversing the edges
        }
        return g;
    }

    bool isStronglyConnceted(){
        return this->isConnected() && reverse().isConnected();
    }

    bool hasEulerianCycle(){
        if(!isStronglyConnceted()){
            return false;
        }
        std::vector<int> inDegree(vertices);
        std::vector<int> outDegree(vertices);

        for (size_t i = 0; i < data.size(); i++)
        {
            inDegree[data[i].to]++;
            outDegree[data[i].from]++;
        }

        for (size_t i = 0; i < vertices; i++)
        {
            if(inDegree[i] != outDegree[i])
                return false;
        }
        return true;
        
    }

    bool hasEulerianPath(int from, int to){
        //if there are more than 1 components, return false
        if(!isConnected())
            return false;
        //check for strongly connected components(bfs/dfs -> reverse -> bfs/dfs) and inDegree == outDegree
        if(from == to)
            return hasEulerianCycle(); 

        std::vector<int> inDegree(vertices);
        std::vector<int> outDegree(vertices);

        for (size_t i = 0; i < data.size(); i++)
        {
            inDegree[data[i].to]++;
            outDegree[data[i].from]++;
        }
        for (size_t i = 0; i < vertices; i++)
        {
            bool validStart = i == from && outDegree[i] - inDegree[i] == 1 && outDegree[i] > 0;
            bool validEnd = i == to && inDegree[i] - outDegree[i] == 1 && inDegree[i] > 0;
            bool validBetween = outDegree[i] == inDegree[i] && outDegree[i] > 0;
            if(validStart || validEnd)
                continue;
            else if (i != from && i != to && validBetween)
                continue;
            else
                return false;
        }
        return true;
        
    }

    void printEdges(){
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << data[i].from << ' ' <<data[i].to << '\n';
        }
        
    }
};