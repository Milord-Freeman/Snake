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
    newApple();
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

int Snake::newApple()
{
    segment nextApple;
    nextApple.x = 6;
    nextApple.y = 7;
    apples.push_back(nextApple);
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
        body.insert(body.begin(), nextPlace);
    } else {
        for (auto currentSegment : body){
            segment buffer = currentSegment;
            currentSegment = nextPlace;
            nextPlace = buffer;
        }
    }



    return 0;
}

int Snake::drawMap()
{
    for (int h = 0; h <= ourMap.height; h++){
        for (int w = 0; w <= ourMap.widht; w++){
            segment currentSegment;
            currentSegment.x = h;
            currentSegment.y = w;
            if (isBorder(currentSegment)) cout << "+";
            else if (isBody(currentSegment)) cout << "D";
            else if (isApple(currentSegment)) cout << "J";
            else cout << "o";
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

bool Snake::isApple(Snake::segment currentSegment)
{
    for (auto apple : apples){
        if ((currentSegment.x == apple.x) and (currentSegment.y == apple.y)) {
            return true;
        }
    }
    return false;
}

bool Snake::isBorder(Snake::segment currentSegment)
{
    if ((currentSegment.x == 0) or (currentSegment.x == ourMap.height) or
        (currentSegment.y == 0) or (currentSegment.y == ourMap.widht)){
        return true;
    } else return false;
}

bool Snake::isBody(Snake::segment currentSegment)
{
    for (auto bodies : getBody()) {
        if ((bodies.x == currentSegment.x) and (bodies.y == currentSegment.y)){
            return true;
        }
    }
    return false;
}
