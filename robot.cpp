#include "robot.h"

Robot::Robot(const std::string &n, int startX, int startY) : name(n), x(startX), y(startY) {}

void Robot::move(char direction, int steps)
{
    switch (direction)
    {
    case 'N':
        y += steps;
        break;
    case 'E':
        x += steps;
        break;
    case 'S':
        y -= steps;
        break;
    case 'W':
        x -= steps;
        break;
    }
}

std::string Robot::getName() const
{
    return name;
}

int Robot::getX() const
{
    return x;
}

int Robot::getY() const
{
    return y;
}
