/*
 * Function template example
 */

#include <iostream>

template <typename T>

T square(T x) {
    return  x*x;
}

int main() {
    std::cout << square(5) << std::endl;
    std::cout << square(5.5) << std::endl;
    return 0;
}

// Build:  g++ func_templ.cpp -o func_templ