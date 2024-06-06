#include "ryan.hpp"

Ryan::Ryan(Vector2 position)
{
    this -> position = position;
}

Ryan::~Ryan()
{

}

void Ryan::Draw()
{
    DrawRectangle(position.x, position.y, 10, 10, WHITE);
}

void Ryan::moveRyan()
{
    if(IsKeyDown(KEY_UP)){
        position.y = 346;
        position.x = 445;     
    }
    if(IsKeyDown(KEY_LEFT)){
        position.y = 445;
        position.x = 341;
    }
    if(IsKeyDown(KEY_RIGHT)){
        position.y = 445;
        position.x = 547;
    }
    if(IsKeyDown(KEY_DOWN)){
        position.y = 542;
        position.x = 445;
    }
}
