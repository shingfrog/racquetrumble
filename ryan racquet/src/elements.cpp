#include "elements.hpp"
#include <raylib.h>

Ball::Ball(Vector2 position, double speed, int radius, Color color){
    this -> position = position;
    this -> speed = speed;
    this -> radius = radius;
    this -> color = color;
    //this -> scale = scale;
}

void Ball::Draw()
{
    DrawCircle(position.x, position.y, radius, color);
}

void Ryan::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

// int UpdateMultiplier() {
//   static int speedMultiplier = 1;

//   if (int(GetFrameTime()) % 8 == 0) {
//     speedMultiplier++;
//   }
//   return speedMultiplier;
// }

// void Draw() 
// {
//     DrawTextureEx(ballTexture, Vector2{x, y}, 0.0, 0.02, WHITE);
// }

void Ryan::Update()
{
    if(IsKeyDown(KEY_UP)){
        y = 350;
        x = 635;
    }

    if(IsKeyDown(KEY_LEFT)){
        y = 395;
        x = 590;
    }

    if(IsKeyDown(KEY_RIGHT)){
        y = 395;
        x = 690;
    }

    if(IsKeyDown(KEY_DOWN)){
        y = 450;
        x = 635;
    }
}

// void Enemy::Draw()
// {
//     DrawRectangle(x, y, width, height, WHITE);
// }