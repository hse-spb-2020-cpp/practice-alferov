#include <expression.h>
#include <parser.h>
#include <calculator.h>

#include <string>
#include <iostream>
#include <optional>


int main() {
    std::string input;
    std::cin >> input;

    auto expr = parse(input);
    if (expr.has_value()) {
        std::cout << calculate(expr.value()) << std::endl;
    } else {
        std::cout << "could not parse" << std::endl;
    }

    return 0;
}
