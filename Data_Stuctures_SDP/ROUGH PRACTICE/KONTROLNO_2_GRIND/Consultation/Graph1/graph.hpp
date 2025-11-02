#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>

class Graph{
private:
    struct Edge
    {
        int from, to, weight;
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight){}
    };
    std::vector<std::vector<Edge>> data;

    void copy(const Graph& other){
        data = other.data;
    }

public:
    Graph() = default;
    ~Graph() = default;
    Graph(const Graph& other){copy(other);}
    Graph(Graph&& other) noexcept{std::swap(data, other.data);}
    Graph& operator=(const Graph& other){
        if(this != &other)
            data = other.data;
        return *this;
    }
    Graph& operator=(Graph&& other){
        if(this != &other)
            std::swap(data,other.data);
        return *this;
    }

    void addEdge(int v1, int v2, int weight){//not oriented
        data[v1].push_back({v1,v2,weight});
        data[v2].push_back({v2,v1,weight});
    }

    void deserialize(std::ifstream& stream){
        int vertices, edges;
        stream >> vertices >> edges;
        data.resize(vertices); //resize is more suitable here cus i want the vectors initilized already
        for (size_t i = 0; i < edges; i++)
        {
            int from, to, weight;
            stream >> from >> to >> weight;
            addEdge(from, to, weight);//fix when indexing starts from 1
        }
    }

    int findComponents(){
        std::vector<bool> used(data.size(), false);
        std::queue<int> q;
        q.push(0);
        used[0] = true;
        int components = 1;

        for(;;){
            //case when we are finished with 1 of the components
            if(q.empty()){
                int newStart = -1;
                for (size_t i = 0; i < used.size(); i++)
                    if(!used[i])
                        newStart = i;
                if(newStart > 0){
                    q.push(newStart);
                    components++;
                }
                else
                    break;
            }
            int curr = q.front();
            q.pop();
            used[curr] = true;

            //case when the vertext is isolated
            if(curr > data.size()-1)
                continue;

            for (size_t i = 0; i < data[curr].size(); i++)
            {
                int destination = data[curr][i].to;
                if(!used[destination])
                    q.push(destination);
            }
        }
        return components;
    }

    std::vector<int> scuffedDijstra(int start){
        //pretty sure that keeping used vertices was redundant here
        std::queue<int> q;
        std::vector<int> distances(data.size(), INT32_MAX);
        q.push(start);
        distances[start] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for (size_t i = 0; i < data[curr].size(); i++)
            {
                //if next step helps shrink the dist then take it!
                int destination = data[curr][i].to;
                int weight = data[curr][i].weight;
                if(distances[curr] + weight < distances[destination]){
                    q.push(destination);
                    distances[destination] = distances[curr] + weight;
                }
            }
            
        }
        return distances;
    }
};