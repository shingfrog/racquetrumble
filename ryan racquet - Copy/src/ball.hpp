#pragma once
#include <raylib.h>
#include "enemy.hpp"
#include "ryan.hpp"

class Game;

class Ball
{
    public:
    Ball(Vector2 position, Texture2D ballImage, double speed);
    ~Ball();
    void Draw();
    void Update(Ryan* ryan);

    Texture2D GetTexture();
    Vector2 getBallPosition();

    bool active;
    int score = 0;

    private:
    Texture2D ballImage;
    Vector2 position;
    double speed;
};
