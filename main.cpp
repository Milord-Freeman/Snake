#include <iostream>
#include <snake.h>

using namespace std;

int main()
{
    Snake newSnake;
    newSnake.drawMap(newSnake.getBody());
    return 0;
}
