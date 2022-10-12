#include <iostream>
#include <string>

int main() {
    std::string string;
    std::cin >> string;
    string += "\\0";
    std::cout << string;
    return 0;
}
