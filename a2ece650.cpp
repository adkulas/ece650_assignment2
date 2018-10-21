// compile: g++ -o a2ece650 ../a2ece650.cpp ../graph.cpp
#include <iostream>
#include <limits>
#include "a2ece650.hpp"
#include "graph.hpp"


int main() {
    char cmd;
    int vertices;
    int start_vertex;
    int end_vertex;
    std::string edges;
    Graph* g = NULL;

    std::cout << "Program Start" << std::endl;
    while(std::cin >> cmd){    
        //std::cin >> cmd;
        switch(cmd) {
            case 'V': case 'v':
                std::cin >> vertices;
                std::cout << "Vertex cmd entered " << vertices << std::endl;
                
                // Create a new graph
                delete g;
                g = NULL;
                g = new Graph(vertices);

                std::cout << g << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;
            
            case 'E': case 'e':
                std::cin >> edges;
                std::cout << "Edge cmd entered " << edges << std::endl;

                std::cout << g->get_vertices() << std::endl;
                g->add_edge(2,6);
                g->add_edge(2,8);
                g->add_edge(2,5);
                g->add_edge(6,5);
                g->add_edge(5,8);
                g->add_edge(6,10);
                g->add_edge(10,8);

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;

            case 'S': case 's':
                std::cin >> start_vertex >> end_vertex;
                std::cout << "Shortest cmd entered " << start_vertex << ' ' << end_vertex << std::endl;
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
    // std::string line;
    // while (std::getline(std::cin, line)) //Take input until EOF character is found
    //     {
    //         std::cout << line << std::endl;
    //     }
    std::cout << "This is the end" << std::endl;
    Graph test(15);
    test.add_edge(2,6);
    test.add_edge(2,8);
    test.add_edge(2,5);
    test.add_edge(6,5);
    test.add_edge(5,8);
    test.add_edge(6,10);
    test.add_edge(10,8);
    test.print_shortest_path(2,10);
    Graph test2(5);
    test2.add_edge(0,2);
    test2.add_edge(2,1);
    test2.add_edge(2,3);
    test2.add_edge(3,4);
    test2.add_edge(4,1);
    test2.print_shortest_path(4,0);
    
    return 0;
}