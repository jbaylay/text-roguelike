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

    std:: size_t playerX = 4;
    std:: size_t playerY = 2;

    for (std::size_t y = 0; y < map.size(); y++) {
        for(std::size_t x = 0; x < map[y].size(); x++){
            if(x == playerX && y ==playerY){
                std::cout << "@";
            } else{
                std::cout << map[y][x];
            }
        }
        std::cout << "\n";
    }

    return 0;
}   