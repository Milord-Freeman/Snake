#include <iostream>
#include <snake.h>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    Snake newSnake;

    while(!newSnake.nextStep(newSnake.getDirection())){
        newSnake.drawMap();
        for (int i = 0; i<10; i++){
            if (newSnake.switchDirection()) return 0;
            else std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // sleep 5 sec
    }
    return 0;
}
