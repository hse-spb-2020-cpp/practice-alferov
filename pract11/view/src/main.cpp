#include "view.h"
#include <iostream>
#include <sstream>

int main() {
    View v;
    v.foo();
    std::cout << std::boolalpha << isBar << std::endl;

    std::string s;
    std::getline(std::cin, s);
    std::stringstream ss(s);
    int x, y;
    char space;

    if (!(ss >> x))
    ss >> space;


    return 0;
}
