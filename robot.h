#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Robot {
private:
    std::string name;
    int x, y;

public:
    Robot(const std::string& n, int startX, int startY);

    void move(char direction, int steps);

    // Getters
    std::string getName() const;
    int getX() const;
    int getY() const;
};

#endif // ROBOT_H
