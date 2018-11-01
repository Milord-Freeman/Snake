#include "snake.h"
#include <iostream>
#include <vector>

using namespace std;

Snake::Snake()
{
    cout << "Welcome to snake!" << "\n";
    setHeight(10);
    setWight(10);
    setDirection(RIGHT);

    segment startPlace;
    startPlace.x = 3;
    startPlace.y = 4;
    body.push_back(startPlace);
}

std::vector<Snake::segment> Snake::getBody()
{
    return body;
}

Snake::segment Snake::getHead()
{
    return body[0];
}

int Snake::setDirection(Snake::directions dir)
{
    direction = dir;
    return 0;
}

int Snake::nextStep(Snake::directions direction)
{
    segment headPlace = getHead();

    segment nextPlace = headPlace;
    switch (direction){
    case UP: nextPlace.x--; break;
    case DOWN: nextPlace.x++; break;
    case LEFT: nextPlace.y--; break;
    case RIGHT: nextPlace.y++; break;
    }

    if (isBorder(nextPlace)) return 1;
    else if (isApple(nextPlace)) {
        //TODO: make grow-up.
    } else {
        for (auto currentSegment : body){
            segment buffer = currentSegment;
            currentSegment = nextPlace;
            nextPlace = buffer;
        }
    }



    return 0;
}

int Snake::drawMap(std::vector<Snake::segment> ourBody)
{
    for (int i = 0; i < ourMap.height; i++){
        for (int j = 0; j < ourMap.widht; j++){
            if ((i==0) or (j == 0) or
                (i == ourMap.height - 1) or
                (j == ourMap.widht - 1)){
                cout << "1";
            } else {
                for (auto seg : ourBody){
                    if ((seg.x == i) and
                        (seg.y == j)){
                        cout << "8";
                    } else { cout << "0";};
                }
            }
        }
        cout << "\n";
    }

    return 0;
}

int Snake::setWight(int widht)
{
    ourMap.widht = widht;
    return 0;
}

int Snake::setHeight(int height)
{
    ourMap.height = height;
    return 0;
}

bool Snake::isApple(Snake::segment)
{
    return false;
}

bool Snake::isBorder(Snake::segment currentSegment)
{
    if ((currentSegment.x == 0) or (currentSegment.x == ourMap.height) or
        (currentSegment.y == 0) or (currentSegment.y == ourMap.widht)){
        return true;
    } else return false;
}
