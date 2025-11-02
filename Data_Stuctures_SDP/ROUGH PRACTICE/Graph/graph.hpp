#pragma once

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <vector>
#include <list>
#include <fstream>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stdexcept>
#include <unordered_map>
#include <set>

class Graph{
private:
    struct Edge{
        int source, destination, weight;
        Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight){}
        bool operator<(const Edge& other)const{return weight > other.weight;}
    };

    
    std::vector<std::vector<Edge>> data;

public:
    Graph() = default;
    Graph(unsigned vertices) : data(std::vector<std::vector<Edge>>(vertices)){}
    ~Graph() = default;
    Graph(const Graph& other) = default;
    Graph(Graph&& other) noexcept {std::swap(data,other.data);}
    Graph& operator=(const Graph& other){
        if(this != &other)
            *this = Graph(other); //strong exception safety ;3
        return *this;
    }
    Graph& operator=(Graph&& other) noexcept {
        if(this != &other)
            std::swap(data, other.data);
        return *this;
    }

    void addEdge(unsigned from, unsigned to, int weight){
        if (from >= data.size() || to >= data.size())
            data.resize(std::max(from, to) + 1);
        data[from].push_back(Edge(from,to,weight));
        data[to].push_back(Edge(to, from, weight)); //remove this line and its not directed
    }
    void removeEdge(unsigned from, unsigned to){//removes the first edge that leats to the desired dest
        for (size_t i = 0; i < data[from].size(); i++)
        {
            if(data[from][i].destination == to){
                std::swap(data[from][i], data[from].back());
                data[from].pop_back();
                return;
            }
        }
    }

    void deserialise(std::istream& in){
        int verices, edges;
        in >> verices >> edges;
        for (size_t i = 0; i < edges; i++)
        {
            unsigned from, to, weight;
            in >> from >> to >> weight;
            addEdge(from,to,weight);
        }
    }
    void serialise(std::ostream& out)const{
        std::set<std::pair<int,int>> usedEdges;
        int vertices, edges = 0;
        vertices = data.size()-1;
        for (int i = 0; i < data.size(); i++) 
            edges += data[i].size();
        out << vertices << ' ' << (edges / 2) << '\n';
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < data[i].size(); j++){
                int source = i;
                int destination = data[i][j].destination;
                if(usedEdges.count({source,destination}) == 0){
                    out << source << ' ' << destination<< ' ' << data[i][j].weight << '\n';
                    usedEdges.insert({source,destination});
                    usedEdges.insert({destination,source});
                }
            }
                
    }

    void DFS_Helper(const int& curr, std::vector<int>& path, std::unordered_set<int>& used) const{
        path.push_back(curr);
        used.insert(curr);
        for (size_t i = 0; i < data[curr].size(); i++)
            if(used.count(data[curr][i].destination) == 0)
                DFS_Helper(data[curr][i].destination,path,used);
    }

    std::vector<int> DFS(const int& start)const {
        if(start >= data.size())
            throw std::out_of_range("Error! No such vertex!");
        std::unordered_set<int> used;
        std::vector<int> path;
        DFS_Helper(start,path,used);
        return path;
    }

    std::vector<int> BFS(const int& start)const{
        std::queue<int> queue;
        queue.push(start);
        std::vector<int> res;
        std::unordered_set<int> used;
        while(!queue.empty()){
            int elem = queue.front();
            res.push_back(elem);
            used.insert(elem);
            queue.pop();
            for (size_t i = 0; i < data[elem].size(); i++)
            {   
                if(!used.count(data[elem][i].destination)){
                    queue.push(data[elem][i].destination); 
                    used.insert(data[elem][i].destination);
                }

            }
        }
        return res;
    }
    //here we are searching for the shortest distance to each thingy
    std::vector<int> Dijkstra(const int& start) const {
        std::vector<int> distances(data.size(), INT16_MAX);
        std::priority_queue<Edge> queue; // Min-heap for {distance, node}
        std::unordered_set<int> visited; // Set to track visited nodes
        
        // Start from the source node
        distances[start] = 0;
        queue.push({start, start, 0}); // Push {node, distance} into the priority queue

        while (!queue.empty()) {
            int curr_source = queue.top().source;
            int curr_destination = queue.top().destination;
            int curr_distance = queue.top().weight;
            queue.pop();
            // Skip if this node is already visited
            if (visited.count(curr_destination)) continue;
            else visited.insert(curr_destination);

            // Process all neighbors of the current node
            for (int i = 0; i < data[curr_destination].size(); i++) {
                Edge edge(data[curr_destination][i]);
                int neighbor = edge.destination;
                int weight = edge.weight;

                // Relaxation step: Update distance if a shorter path is found
                if (distances[curr_destination] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[curr_destination] + weight;
                    if(visited.count(neighbor) == 0)
                        queue.push({curr_destination,neighbor,distances[neighbor]});
                }
            }
        }

        return distances;
    }
    
    Graph Prim() {   
        unsigned start = 1;     
        Graph result;
        std::priority_queue<Edge> queue; 
        std::unordered_set<int> visited; 
        if(data.empty())
            return result;
        
        visited.insert(start);
        insertEdgesToQueue(start, queue, visited);

        while (!queue.empty()) {
            int curr_source = queue.top().source;
            int curr_dest = queue.top().destination;
            int curr_distance = queue.top().weight;
            
            queue.pop();
           
            if (visited.count(curr_dest)) continue;
            std::cout << "=====" << curr_source<< "=====" << curr_dest<< "=====" << curr_distance << '\n';
            visited.insert(curr_dest);
            result.addEdge(curr_source, curr_dest, curr_distance); //not oriented

            insertEdgesToQueue(curr_dest, queue, visited);

        }
        return result;
    }
    void insertEdgesToQueue(int curr_dest, std::priority_queue<Edge>& queue, std::unordered_set<int>& visited){
        for (int i = 0; i < data[curr_dest].size(); i++) {
            Edge edge(data[curr_dest][i]);
            if(visited.count(edge.destination) == 0)
                queue.push({edge.source, edge.destination, edge.weight});
        }
    }
    // std::vector<std::pair<int,int>> BellmanFord(const int& start)const {}
    // std::vector<std::pair<int,int>> FloydWarshall()const {}


    // //Graph Kruskal()const {}
    
    // std::vector<int> TopologicalSort()const {}
    // bool hasCycle()const {}

    // friend bool cmpEdges(const Edge& A, const Edge& B){return A.weight < B.weight;}
};


#endif