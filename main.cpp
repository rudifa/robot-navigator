#include <iostream>
#include "game.h"

int main()
{
    Game game(10, 10); // Create a 10x10 map

    game.addRobot("R1", 0, 0);
    game.addRobot("R2", 9, 9);

    std::cout << "Initial map:" << std::endl;
    game.displayMap();

    game.moveRobot("R1", 'E', 3);
    game.moveRobot("R1", 'N', 2);
    game.moveRobot("R2", 'W', 4);
    game.moveRobot("R2", 'S', 3);

    std::cout << "\nMap after movements:" << std::endl;
    game.displayMap();

    return 0;
}
