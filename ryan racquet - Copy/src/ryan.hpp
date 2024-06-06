#pragma once
#include <raylib.h>

class Ryan
{
    public:
    Ryan(Vector2 position);
    ~Ryan();
    void Draw();
    void moveRyan();

    Vector2 position;
    
    private:
    Texture2D ryanImage;
};