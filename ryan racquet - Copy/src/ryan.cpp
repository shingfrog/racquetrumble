#include "ryan.hpp"

Ryan::Ryan(Vector2 position)
{
    this -> position = position;
    this -> texture = ryanImageUp;
    healthDecreased = false;
}

Ryan::~Ryan()
{

}

void Ryan::Draw()
{
    DrawTextureV(texture, position, WHITE);
}

void Ryan::moveRyan()
{
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        position.y = 360;
        position.x = 408; 
        texture = ryanImageUp;
    }
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        position.y = 439;
        position.x = 354;
        texture = ryanImageLeft;    
    }
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        position.y = 410;
        position.x = 518;
        texture = ryanImageRight;   
    }
    if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        position.y = 512;
        position.x = 440;
        texture = ryanImageDown; 
    }
}

float Ryan::GetWidth()
{
    return (float)GetTexture().width;
}

float Ryan::GetHeight()
{
    return (float)GetTexture().height;

}

void Ryan::Reset()
{
    position = {455, 455};
    texture = ryanImageUp;
    health = 3;
}

Texture2D Ryan::GetTexture()
{
    if (position.x == 408){
        return ryanImageUp;
    } else if (position.x == 354){
        return ryanImageLeft;
    } else if (position.x == 518){
        return ryanImageRight;
    } else if (position.x == 440){
        return ryanImageDown;
    }

    return ryanImageUp;
}
