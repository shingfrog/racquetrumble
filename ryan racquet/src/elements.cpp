#include "elements.hpp"
#include <raylib.h>

Ryan::Ryan(Vector2 position, float width, float height, int health) 
{
    this -> position = position;
    this -> width = width;
    this -> height = height;
    this -> health = health;
}

void Ryan::Draw() 
{
  DrawRectangle(position.x, position.y, width, height, WHITE);
}

void Ryan::Update() 
{
    if(IsKeyDown(KEY_UP)){
        position.y = 425;
        position.x = 445;     
    }
    if(IsKeyDown(KEY_LEFT)){
        position.y = 445;
        position.x = 425;
    }
    if(IsKeyDown(KEY_RIGHT)){
        position.y = 445;
        position.x = 475;
    }
    if(IsKeyDown(KEY_DOWN)){
        position.y = 475;
        position.x = 445;
    }
}

Ball::Ball(Vector2 position, double speed, int radius, Color color) 
{
    this -> position = position;
    this -> speed = speed;
    this -> radius = radius;
    this -> color = color;
}

void Ball::Draw() {
  DrawCircle(position.x, position.y, radius, color);
}

void Ball::UpdateX(Ryan* ryan, int& score, Rectangle& enemy) 
{
    position.x += speed;

    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
        speed *= -1;
    } else if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{ryan->position.x, ryan->position.y, ryan->width, ryan->height})) {
        speed *= -1;
        score++;
    } else if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, enemy)) {
            speed *= -1;
    }

    if(CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{450, 450, 1, 1})){
        ryan->health -= 1; 
    }
}

void Ball::UpdateY(Ryan* ryan, int& score, Rectangle& enemy) {
    position.y += speed;

    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
        speed *= -1;
    } else if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{ryan->position.x, ryan->position.y, ryan->width, ryan->height})) {
        speed *= -1;
        score++;
    } else if (CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, enemy)) {
        speed *= -1; 
    }

    if(CheckCollisionCircleRec(Vector2{position.x, position.y}, radius, Rectangle{450, 450, 1, 1})){
        ryan->health -= 1; 
    }
}

Enemy::Enemy(const Rectangle& rect)
{
    this -> rect = rect;
} 

void Enemy::Draw() 
{
  DrawRectangle(rect.x, rect.y, rect.width, rect.height, WHITE);
}
