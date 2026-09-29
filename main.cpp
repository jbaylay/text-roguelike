#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> map ={
        "#########",
        "#       #",
        "#       #",
        "#       #",
        "#########"
    };

    for (std::size_t i = 0; i <map.size(); i++) {
        std::cout << map[i] << "\n";
    }

    return 0;
}   