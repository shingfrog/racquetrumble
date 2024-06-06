#pragma once
#include <raylib.h>

class Ryan
{
    public:
    Ryan(Vector2 position);
    ~Ryan();
    void Draw();
    void moveRyan();
    float GetWidth();
    float GetHeight();
    void Reset();
    Texture2D GetTexture();

    Vector2 position;
    Texture2D texture;
    
    int health = 3;
    
    private:
    Texture2D ryanImageUp = LoadTexture("media/faceUp.png");
    Texture2D ryanImageLeft = LoadTexture("media/faceLeft.png");
    Texture2D ryanImageRight = LoadTexture("media/faceRight.png");
    Texture2D ryanImageDown = LoadTexture("media/faceDown.png");

};
