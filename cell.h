#ifndef CELL_H
#define CELL_H

struct coordinates {
    int x, y;
};

bool operator == (coordinates const &left, coordinates const &right){
    if ((left.x == right.x) and (left.y == right.y)) return true;
    else return false;
};

class Cell
{
public:
    Cell(coordinates);
    bool isBorder();
    bool isBody();
    bool isApple();
    bool isFree();

private:
    coordinates coordinate;
};

#endif // CELL_H
