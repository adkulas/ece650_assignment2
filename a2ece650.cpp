// compile: g++ -o a2ece650 ../a2ece650.cpp ../graph.cpp -std=c++11
#include <iostream>
#include <limits>
#include <regex>
#include "a2ece650.hpp"
#include "graph.hpp"

std::vector< std::pair<int,int> > parse(std::string s) {
    std::pair<int, int> edge;
    std::vector< std::pair<int,int> > result;
    
    // using regex
    try {
        std::regex re("[0-9]+"); //match consectuive numbers
        std::sregex_iterator next(s.begin(), s.end(), re);
        std::sregex_iterator end;
        while (next != end) {
            std::smatch match1;
            std::smatch match2;
            
            match1 = *next;
            next++;
            // iterate to next match
            if (next != end) {
                match2 = *next;
                edge.first = std::stoi(match1.str());
                edge.second = std::stoi(match2.str());
                result.push_back(edge);
                next++;
            }
        } 
    } 
    catch (std::regex_error& e) {
        result.clear();
    }

    return result;
}

int main() {
    char cmd;
    int vertices;
    int start_vertex;
    int end_vertex;
    std::string edges_input;
    std::vector< std::pair<int,int> > edges;
    Graph* g = new Graph(0);

    while(std::cin >> cmd){    
        //std::cin >> cmd;
        switch(cmd) {
            
            // V command to create graph
            case 'V': case 'v':
                std::cin >> vertices;      
                // Create a new graph
                delete g;
                g = new Graph(vertices);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;
            
            // E command to specify edges in graph
            case 'E': case 'e':
                // E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}
                std::cin >> edges_input;
                edges = parse(edges_input);
                for (int i=0; i < edges.size(); i++) {
                    if (g->get_vertices() >= edges[i].first || 
                        g->get_vertices() >= edges[i].second) {
                            g->add_edge(edges[i].first, edges[i].second); 
                    } else {
                        std::cerr << "Error: Attempted to add edge to vertex that does not exist"
                                  << std::endl;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;

            // s command for shortest path
            case 'S': case 's':
                std::cin >> start_vertex >> end_vertex;
                g->print_shortest_path(start_vertex, end_vertex);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;

            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: command not recognized" << std::endl;
        }
    }

    delete g;

    return 0;
}