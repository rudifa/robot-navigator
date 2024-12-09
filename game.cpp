#include "game.h"
#include <iostream>
#include <algorithm>

Game::Game(int width, int height) : mapWidth(width), mapHeight(height) {}

void Game::addRobot(const std::string &name, int x, int y)
{
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight)
    {
        robots.emplace_back(name, x, y);
    }
    else
    {
        std::cout << "Invalid starting position for robot " << name << std::endl;
    }
}

bool Game::moveRobot(const std::string &name, char direction, int steps)
{
    auto it = std::find_if(robots.begin(), robots.end(),
                           [&name](const Robot &r)
                           { return r.getName() == name; });

    if (it != robots.end())
    {
        int oldX = it->getX();
        int oldY = it->getY();
        it->move(direction, steps);

        if (it->getX() >= 0 && it->getX() < mapWidth && it->getY() >= 0 && it->getY() < mapHeight)
        {
            return true;
        }
        else
        {
            it->move(direction, -steps); // Move back if out of bounds
            std::cout << "Movement out of bounds. Robot " << name << " stays at (" << oldX << ", " << oldY << ")" << std::endl;
            return false;
        }
    }

    std::cout << "Robot " << name << " not found." << std::endl;
    return false;
}

void Game::displayMap() const
{
    std::vector<std::vector<char>> map(mapHeight, std::vector<char>(mapWidth, '.'));

    for (const auto &robot : robots)
    {
        int x = robot.getX();
        int y = robot.getY();
        if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight)
        {
            map[y][x] = robot.getName()[0]; // Use first letter of robot's name
        }
    }

    for (int y = mapHeight - 1; y >= 0; --y)
    {
        for (int x = 0; x < mapWidth; ++x)
        {
            std::cout << map[y][x] << ' ';
        }
        std::cout << std::endl;
    }
}
