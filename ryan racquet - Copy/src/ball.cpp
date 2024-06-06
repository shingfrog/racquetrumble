#include "ball.hpp"

Ball::Ball(Vector2 position, Texture2D ballImage, double speed)
{
    this -> ballImage = LoadTexture("media/ball.png");
    this -> position = position;
    this -> speed = speed;
    active = true;
}

Ball::~Ball()
{
}

void Ball::Draw()
{
    if(active)
        DrawTextureV(ballImage, position, WHITE);
}

void Ball::Update(Ryan* ryan)
{
    if (position.x == 450) {
        if(position.y >= 450)
            position.y += -speed;
        else
            position.y += speed;
    } else if (position.y == 450) {
        if(position.x >= 450)
            position.x += -speed;
        else
            position.x += speed;
    }

    if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{ryan->position.x, ryan->position.y, (float)ryan->GetWidth(), (float)ryan->GetHeight()})){
        speed *= -1;
    }

    if (position.x >= 433 && position.x <= 450 && position.y >= 433 && position.y <= 450) {
        active = false; 
        ryan->health--;
    }


    if(active){
        if(position.x > GetScreenWidth() || position.y > GetScreenHeight() || position.x < 0 || position.y < 0 ){
            active = false;
        }
    }
}

Texture2D Ball::GetTexture()
{
    return ballImage;
}

Vector2 Ball::getBallPosition()
{
    return position;
}

