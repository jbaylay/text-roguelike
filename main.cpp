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

    bool running = true;
    while (running) {
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

        char command;
        std::cin >> command;

        std::size_t newX = playerX;
        std::size_t newY = playerY;

        if (command == 'w'){
            newY--;
        } else if (command == 'a'){
            newX--;
        } else if (command == 's'){
            newY++;      
        } else if (command == 'd'){
            newX++;
        } else if (command == 'q'){
            running = false;
        }

        if (map[newY][newX] != '#') {
            playerX = newX;
            playerY = newY;
        }

    }

    return 0;
}   