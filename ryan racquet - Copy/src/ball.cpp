#include "ball.hpp"
#include <ctime>


Ball::Ball(Vector2 position, Texture2D ballImage, double speed)
{
    this -> ballImage = LoadTexture("media/ball.png");
    this -> position = position;
    this -> speed = speed;
    active = true;
}

Ball::~Ball()
{
    //UnloadTexture(ballImage);
}

void Ball::Draw()
{
    if(active)
        DrawTextureV(ballImage, position, WHITE);
}

void Ball::Update()
{
    if (position.x == 450) {
        if(position.y > 450)
            position.y += -speed;
        else
            position.y += speed;
    } else if (position.y == 450) {
        if(position.x > 450)
            position.x += -speed;
        else
            position.x += speed;
    }

    if(active){
        if(position.x > GetScreenWidth() || position.y > GetScreenHeight() || position.x < 0 || position.x < 0 ){
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


// int Ball::updateSpeed(){
//     SetRandomSeed(time(NULL));
//     return GetRandomValue(1, 2);
// }

// void Ball::updateX(Ryan* ryan)
// {
//     position.x += speed;

//     int r = 6;
//     if (position.x + r >= GetScreenHeight() || position.x - r <= 0) {
//         speed *= -1;
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{24, 442, 7, 20})) {
//         speed *= -1;
//         speed = updateSpeed();
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{868, 438, 7, 20})) {
//         speed = updateSpeed();
//         speed *= -1;
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{ryan->position.x, ryan->position.y, 20, 7})) {
//         speed *= -1;
//         score++;
//     } 
// }

// void Ball::updateY(Ryan* ryan)
// {
//     position.y += speed;

//     int r = 6;
//     if (position.y + r >= GetScreenWidth() || position.y - r <= 0){
//         speed *= -1;
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{439, 29, 20, 7})) {
//         speed *= -1;
//         speed = updateSpeed();
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{440, 862, 20, 7})) {
//         speed = updateSpeed();
//         speed *= -1;
//     } else if (CheckCollisionRecs(Rectangle{position.x, position.y, 12, 12}, Rectangle{ryan->position.x, ryan->position.y, 20, 7})) {
//         speed *= -1;
//         score++;
//     } 

// }

