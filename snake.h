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
    directions getDirection();
    int setDirection(directions);
    segment getApple();
    int newApple();
    int nextStep(directions);
    int drawMap(std::vector<segment>);


private:
    std::vector<segment> body;
    directions direction;
    segment apple;
    map ourMap;
    int setWight(int);
    int setHeight(int);

};

#endif // SNAKE_H
