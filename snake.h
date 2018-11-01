#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

class Snake
{
public:
    Snake();

    struct segment{
        int x, y;
    };
    struct map{
        int widht, height;
    };

    enum directions{UP, DOWN, LEFT, RIGHT};

    std::vector<segment> getBody();
    segment getHead();
    directions getDirection();
    int setDirection(directions);
    segment getApple();
    int newApple();
    int nextStep(directions);
    int drawMap();


private:
    std::vector<segment> body;
    directions direction;
    std::vector<segment> apples;
    map ourMap;

    int setWight(int);
    int setHeight(int);
    bool isApple(segment);
    bool isBorder(segment);
    bool isBody(segment);

};

#endif // SNAKE_H
