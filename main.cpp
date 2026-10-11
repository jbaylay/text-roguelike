#include <iostream>
#include <string>
#include <vector>

struct Entity
{
    std::size_t x;
    std::size_t y;
    char symbol;
};

void drawMap(const std::vector<std::string> &map, const Entity &player, const std::vector<Entity> &enemies)
{

    for (std::size_t y = 0; y < map.size(); y++)
    {
        for (std::size_t x = 0; x < map[y].size(); x++)
        {
            bool drawn = false;

            if (x == player.x && y == player.y)
            {
                std::cout << player.symbol;
                drawn = true;
            }

            for (std::size_t i =0; i < enemies.size(); i++)
            {
                if (x == enemies[i].x && y == enemies[i].y)
                {
                    std::cout << enemies[i].symbol;
                    drawn = true;
                }
            }

            if (!drawn)
            {
                std::cout << map[y][x];
            }
        }
        std::cout << "\n";
    }
}

void movePlayer(const std::vector<std::string> &map, char command, Entity &player)
{

    std::size_t newX = player.x;
    std::size_t newY = player.y;

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
        player.x = newX;
        player.y = newY;
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

    Entity player = {4, 2, '@'};

    std::vector<Entity> enemies = {
        {6, 1, 'g'},
        {2, 3, 'g'}};

    bool running = true;
    while (running)
    {

        drawMap(map, player, enemies);

        char command;
        std::cin >> command;

        movePlayer(map, command, player);

        if (command == 'q')
        {
            running = false;
        }
    }

    return 0;
}