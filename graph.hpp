#pragma once

#include <iostream>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector< std::vector<int> > graph;
    std::vector<int> pred;
    std::vector<int> dist;

    bool breadth_first_search(int src, int dest);

public:
    Graph( int vertices = 0 );

    /// Accessors
    void print_shortest_path(int src, int dest);

    /// Mutators
    void add_edge(int src, int dest);

};