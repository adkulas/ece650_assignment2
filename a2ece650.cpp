// compile: c++ -o complex_main complex_main.cpp
#include <iostream>
#include "a2ece650.hpp"

int main() {
    Complex cx(10, 4);

    std::cout << "Absolute value of " << cx.real() << "+" << cx.imag() << "i"
              << " is " << cx.abs() << "\n";
    
    int firstInt;
    int secondInt;
    std::cin >> firstInt >> secondInt;
    std::cout << firstInt << secondInt << std::endl;
    return 0;
}
