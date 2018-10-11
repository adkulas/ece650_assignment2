#pragma once

// An example of a complex number
// See complex_main.cpp for compilation instructions

#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <climits>

class Graph {
private:
    int vertices;
    std::vector< std::vector<int> > graph;
    std::vector<int> pred;
    std::vector<int> dist;

    bool breadthFirstSearch(int src, int dest);

public:
    Graph( int vertices = 0 );

    /// Accessors
    void shortest_distance() const;

    /// Mutators
    void add_edge(int src, int dest);

};

// Constructor
inline Graph::Graph( int v ):
    vertices(v), graph(v), pred(v), dist(v) {/*empty constructor*/}

inline bool Graph::breadthFirstSearch(int src, int dest) {
    std::list<int> queue;
    bool visited[vertices];

    // initialization: visted to false dist to inf and no predecessors
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // source is first to be visited and 
    // distance from source to itself should be 0 
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // iterate through graph breadth first and halt when destination is found
    while (!queue.empty()) {
        int n = queue.front();
        queue.pop_front();
        for (int i =0; i < graph[n].size(); i++) {
            if (visited[graph[n][i]] == false) 
            {
                visited[graph[n][i]] == true;
                dist[graph[n][i]] = dist[n] + 1;
                pred[graph[n][i]] = n;
                queue.push_back(graph[n][i]);

                if (graph[n][i] == dest) {
                    return true;
                }
            }
        }
    }
    return false;
}

inline void Graph::add_edge(int src, int dest) {
    graph[src].push_back(dest); 
    graph[dest].push_back(src);

    return;
}

void Graph::shortest_distance() const {

    std::cout << "Hello" << vertices << pred.size() << graph.size();
    return;
}
