// compile: g++ -o a2ece650 ../a2ece650.cpp
#include <iostream>
#include <limits>
#include "a2ece650.hpp"


int main() {
    // Complex cx(10, 4);

    // std::cout << "Absolute value of " << cx.real() << "+" << cx.imag() << "i"
    //           << " is " << cx.abs() << "\n";

    char cmd;
    int vertices;
    int vertexStart;
    int vertexEnd;
    std::string edges;

    std::cout << "Program Start" << std::endl;
    while(std::cin >> cmd){    
        //std::cin >> cmd;  
        switch(cmd) {
            case 'V': case 'v':
                std::cin >> vertices;
                std::cout << "Vertex cmd entered " << vertices << std::endl;
                break;
            
            case 'E': case 'e':
                std::cin >> edges;
                std::cout << "Edge cmd entered " << edges << std::endl;
                break;

            case 'S': case 's':
                std::cin >> vertexStart >> vertexEnd;
                std::cout << "Shortest cmd entered " << vertexStart << ' ' << vertexEnd << std::endl;
                break;

            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: command not recognized" << std::endl;
        }
    }

    // std::string line;
    // while (std::getline(std::cin, line)) //Take input until EOF character is found
    //     {
    //         std::cout << line << std::endl;
    //     }
    std::cout << "This is the end" << std::endl;

    return 0;
}