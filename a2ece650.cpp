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
        std::regex re("[0-9]+");
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
                std::cout << std::stoi(match1.str()) << " " << std::stoi(match2.str()) << std::endl;
                edge.first = std::stoi(match1.str());
                edge.second = std::stoi(match2.str());
                result.push_back(edge);
                next++;
            }
        } 
    } 
    catch (std::regex_error& e) {
    // Syntax error in the regular expression
    }

    return result;
}

int main() {
    char cmd;
    int vertices;
    int start_vertex;
    int end_vertex;
    Graph* g = NULL;
    std::string edges_input;
    std::vector< std::pair<int,int> > edges;

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
                std::cin >> edges_input;
                std::cout << "Edge cmd entered " << edges_input << std::endl;

                std::cout << g->get_vertices() << std::endl;

                
                edges = parse(edges_input);
                // for (int i=0; i < edges.size(); i++) {
                //     std::cout << edges[i].first << " " << edges[i].second << std::endl;
                //     edges[i]
                // }

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
    
    std::string s("{<11,2>,<33,4>,<55,6>}");
    std::vector< std::pair<int,int> > ex;
    ex = parse(s);
    std::cout << "test: " << ex[0].first << std::endl;
    return 0;
}