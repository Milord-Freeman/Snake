#include "snake.h"
#include <iostream>
#include <vector>
#include "windows.h" // for system("cls") only
#include "conio.h" // for kbhit and getch only

using namespace std;

Snake::Snake()
{
    cout << "Welcome to snake!" << "\n";
    setHeight(10);
    setWight(10);
    setDirection(RIGHT);
    stepCount = 0;

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

Snake::directions Snake::getDirection()
{
    return direction;
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
    stepCount++; // debug
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
        for (unsigned int i = 0; i < getBody().size(); i++){
            segment buffer = body[i];
            body[i] = nextPlace;
            nextPlace = buffer;
        }
    }



    return 0;
}

int Snake::drawMap()
{
    system("cls"); // Clear sreen, windows only. TODO: multiplatform solution.
    for (int h = 0; h <= ourMap.height; h++){
        for (int w = 0; w <= ourMap.widht; w++){
            segment currentSegment;
            currentSegment.x = h;
            currentSegment.y = w;
            if (isBorder(currentSegment)) cout << "+";
            else if (isBody(currentSegment)) cout << "O";
            else if (isApple(currentSegment)) cout << "A";
            else cout << " ";
        }
        cout << "\n";
    }

    return 0;
}

int Snake::switchDirection()
{
    if (kbhit()) {
        //GetAsyncKeyState(125);
        switch (getch()) {
        case 75: direction = LEFT; break; // LEFT
        case 72: direction = UP; break; // UP
        case 77: direction = RIGHT; break; // RIGHT
        case 80: direction = DOWN; break; // DOWN
        case 27: return 1; // ESC
        default: break; // OTHER
        }
    };
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
