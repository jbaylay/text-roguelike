#include <iostream>
#include <string>
#include <vector>

void drawMap(const std::vector<std::string> &map, std::size_t playerX, std::size_t playerY)
{

    for (std::size_t y = 0; y < map.size(); y++)
    {
        for (std::size_t x = 0; x < map[y].size(); x++)
        {
            if (x == playerX && y == playerY)
            {
                std::cout << "@";
            }
            else
            {
                std::cout << map[y][x];
            }
        }
        std::cout << "\n";
    }
}

void movePlayer(const std::vector<std::string> &map, char command, std::size_t &playerX, std::size_t &playerY)
{

    std::size_t newX = playerX;
    std::size_t newY = playerY;

    if (command == 'w')
    {
        newY--;
    }
    else if (command == 'a')
    {
        newX--;
    }
    else if (command == 's')
    {
        newY++;
    }
    else if (command == 'd')
    {
        newX++;
    }

    if (map[newY][newX] != '#')
    {
        playerX = newX;
        playerY = newY;
    }
}

int main()
{
    std::vector<std::string> map = {
        "#########",
        "#       #",
        "#       #",
        "#       #",
        "#########"};

    std::size_t playerX = 4;
    std::size_t playerY = 2;

    bool running = true;
    while (running)
    {

        drawMap(map, playerX, playerY);

        char command;
        std::cin >> command;

        movePlayer(map, command, playerX, playerY);

        if (command == 'q')
        {
            running = false;
        }
    }

    return 0;
}