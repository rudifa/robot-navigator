#ifndef GAME_H
#define GAME_H

#include <vector>
#include "robot.h"

class Game
{
private:
    std::vector<Robot> robots;
    int mapWidth;
    int mapHeight;

public:
    Game(int width, int height);

    void addRobot(const std::string &name, int x, int y);
    bool moveRobot(const std::string &name, char direction, int steps);
    void displayMap() const;
};

#endif // GAME_H
